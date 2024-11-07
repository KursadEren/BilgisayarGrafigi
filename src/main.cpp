#define GLFW_INCLUDE_NONE

#include "GLWindow.hpp"
#include "shader.hpp"
#include <glm/glm.hpp>

#include "indexbuffer.hpp"
#include "texturemanager.hpp"
#include "vertexarrayobject.hpp"
#include "vertexbuffer.hpp"
#include "shapecreator.h"
using namespace std;

/*
    üçgen noktaları
    her nokta içerisinde  pozisyon(vec3), color(vec4)
    bulunmaktadır.
*/
float vertices[] = {
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
};

unsigned int  indices [] = {
    0,1,2,
    0,2,3
};

int main(int arc, char **argv) {
    Graph::GLWindow window;

    window.create(800, 800);

    Graph::VertexBuffer vertexBuffer;
    Graph::Shader program;
    Graph::VertexArrayObject vertexArray;
    Graph::IndexBuffer indexBuffer;

    program.create();
    program.attachShader("../shaders/vertex.glsl", GL_VERTEX_SHADER);
    program.attachShader("../shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    program.link();

    program.addUniform("uMove");

    string textureName1 = "../images/container.jpg";
    string textureName2 = "../images/container2.jpg";

    Graph::TextureManager::addTextureFromFile(textureName1);
    Graph::TextureManager::addTextureFromFile(textureName2);
    Graph::TextureManager::addTextureFromFile(textureName1);

    vertexBuffer.create(vertices, sizeof(vertices));
    indexBuffer.create(indices, sizeof(indices));
    vertexArray.create();
    vertexArray.setVertexBuffer(&vertexBuffer);
    vertexArray.addVertexAttribute(Graph::VertexAttributeType::Position);
    vertexArray.addVertexAttribute(Graph::VertexAttributeType::Texture);
    vertexArray.activateAttributes();
    vertexBuffer.bind();
    vertexArray.bind();
    indexBuffer.bind();

    glm::vec3 position(0.0f, 0.0f, 0.0f);

    window.setKeyboardFunction([&](int key, int scancode, int action) {

        if (key == GLFW_KEY_LEFT) {
            position.x += 0.1f;
        }
        if (key == GLFW_KEY_RIGHT) {
            position.x -= 0.1f;
        }
        if (key == GLFW_KEY_UP) {
            position.y -= 0.1f;
        }
        if (key == GLFW_KEY_DOWN) {
            position.y += 0.1f;
        }

    });

    window.setRenderFunction([&]() {
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        program.use();

        Graph::TextureManager::activateTexture(textureName1);

        program.setVec3("uMove", position);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);


        Graph::TextureManager::activateTexture(textureName2);
        program.setVec3("uMove", -position);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
    });

    window.render();

    exit(EXIT_SUCCESS);
}