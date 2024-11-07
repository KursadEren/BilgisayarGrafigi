#ifndef GLWindows_hpp
#define GLWindows_hpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "functiontypes.hpp"

class GLFWwindow;

namespace Graph
{

    class GLWindow
    {
    public:
        int create(unsigned int width,unsigned int height);
        void render();
        void setRenderFunction (RenderFunction function);
        void setKeyboardFunction(KeyboardFunction function);
    private:
        GLFWwindow*     m_window;

        static void statickeyboardFunction(GLFWwindow* window, int key, int scancode, int action, int mods);
        RenderFunction      m_renderFunction;
        KeyboardFunction    m_keyboardFunction;
    };
}

#endif