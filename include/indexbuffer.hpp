//
// Created by Mustafa Dağlıoğlu on 7.11.2024.
//

#ifndef indexbuffer_hpp
#define indexbuffer_hpp

namespace Graph {
    class IndexBuffer {
    public:
        void create(void* data, int size);
        void bind();
        void unbind();
        void release();

    private:
        unsigned int m_id;
    };
}

#endif //indexbuffer_hpp
