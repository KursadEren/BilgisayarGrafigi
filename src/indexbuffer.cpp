#include "indexbuffer.hpp"
#include<glad/glad.h>

namespace Graph {
    void IndexBuffer::create(void* data, int size) {
        glGenBuffers(1, &m_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void IndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void IndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBuffer::release() {
        glDeleteBuffers(1, &m_id);
    }
}