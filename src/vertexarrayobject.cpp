#include <glad/glad.h>
#include "vertexarrayobject.hpp"
#include "vertexbuffer.hpp"

namespace Graph
{
    void VertexArrayObject::create()
    {
        glGenVertexArrays(1, &m_id);
    }

    void VertexArrayObject::bind()
    {
        glBindVertexArray(m_id);
    }

    void VertexArrayObject::setVertexBuffer(VertexBuffer *vb)
    {
        m_vb = vb;
        bind();
        m_vb->bind();
    }

    void VertexArrayObject::addVertexAttribute(VertexAttributeType type)
    {
        m_attributes.push_back(type);
    }

    void VertexArrayObject::activateAttributes()
    {
        m_stride = 0;

        for (auto next : m_attributes)
        {
            m_stride += getTypeSize(next);
        }

        int location = 0;

        for (int i = 0; i < m_attributes.size(); i++)
        {
            int typeSize = getTypeSize(m_attributes[i]);
            int elementCount = typeSize / sizeof(float);

            glVertexAttribPointer(i, elementCount, GL_FLOAT, GL_FALSE, m_stride, (void *)location);

            location += typeSize;
            glEnableVertexAttribArray(i);
        }
    }

    int VertexArrayObject::getTypeSize(VertexAttributeType type)
    {
        int size = 0;

        switch (type)
        {
        case VertexAttributeType::Position:
        case VertexAttributeType::Normal:
            size = sizeof(float) * 3;
            break;
        case VertexAttributeType::Color:
            size = sizeof(float) * 4;
            break;
        case VertexAttributeType::Texture:
            size = sizeof(float) * 2;
            break;
        }

        return size;
    }

    void VertexArrayObject::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArrayObject::release()
    {
        glDeleteVertexArrays(1, &m_id);
        m_vb->release();
    }
}