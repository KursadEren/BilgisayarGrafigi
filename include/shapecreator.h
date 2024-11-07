#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include <unordered_map>



namespace Graph {
    class VertexArrayObject ;

    enum class ShapeType {
        square,
        circle,
        cube
      };


    class ShapeCreator {
    public:
        VertexArrayObject *createSquare();
        VertexArrayObject *createCircle();
    private:
        std::unordered_map<ShapeType, VertexArrayObject *> m_vaoMap;
    };
}


#endif


