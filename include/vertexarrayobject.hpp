#ifndef vertexarrayobject_hpp
#define vertexarrayobject_hpp
#include<vector>

namespace Graph {
    using namespace std;

    class VertexBuffer;

    enum class VertexAttributeType {
        Position,
        Color,
        Normal,
        Texture
    };

    using AttributeList = vector<VertexAttributeType>;

    class VertexArrayObject {
        public:
            void create();
            void setVertexBuffer(VertexBuffer* vb);
            void addVertexAttribute(VertexAttributeType type);
            void activateAttributes();
            void bind();
            void unbind();
            void release();
        private:
            int getTypeSize(VertexAttributeType type);
            unsigned int m_id;
            unsigned int m_stride;
            VertexBuffer* m_vb;
            AttributeList m_attributes;
    };
}

#endif