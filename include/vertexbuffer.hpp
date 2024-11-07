#ifndef vertexbuffer_hpp
#define vertexbuffer_hpp

namespace Graph {
    class VertexBuffer {
        public:
            void create(void* data, int size);
            void bind();
            void unbind();
            void release();

        private:
            unsigned int m_id;
    };
}

#endif