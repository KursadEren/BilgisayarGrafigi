#include "shader.hpp"
#include<glad/glad.h>
#include<iostream>
#include<fstream>

using namespace std;

namespace Graph {
    void Shader::create() {
        m_id = glCreateProgram();
    }

    void Shader::attachShader(const string &fileName, unsigned int shaderType) {
        unsigned int shader = glCreateShader(shaderType);

        string source = getShaderFromFile(fileName);

        const char *src = &source[0];

        glShaderSource(shader, 1, &src, NULL);

        glCompileShader(shader);

        glAttachShader(m_id, shader);
    }

    void Shader::link() {
        glLinkProgram(m_id);
    }

    void Shader::use() {
        glUseProgram(m_id);
    }

    void Shader::addUniform(const string &varName) {
        m_uniforms[varName] = glGetUniformLocation(m_id, varName.data());
    }

    void Shader::setVec4(const string &varName, const glm::vec4 &value) {
        if (m_uniforms.count(varName) > 0) {
            glUniform4f(m_uniforms[varName], value.r, value.g, value.b, value.a);
        }
    }

    void Shader::setVec3(const string &varName, const glm::vec3 &value) {
        if (m_uniforms.count(varName) > 0) {
            glUniform3f(m_uniforms[varName], value.r, value.g, value.b);
        }
    }

    void Shader::setFloat(const string &varName, float value) {
        if (m_uniforms.count(varName) > 0) {
            glUniform1f(m_uniforms[varName], value);
        }
    }

    string Shader::getShaderFromFile(const string &path) {
        string data;
        ifstream file(path);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data += line + "\n";
            }
            file.close();
        }
        return data;
    }
}