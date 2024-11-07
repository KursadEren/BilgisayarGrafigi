#include "shapecreator.h"
#include "vertexarrayobject.hpp"
#include "vertexbuffer.hpp"
#include "indexbuffer.hpp"

#include "glm/glm.hpp"

namespace Graph{
    VertexArrayObject ShapeCreator::*createSquare(){
      if(m_vaoMap.count(ShapeType::square) >0 ){
        {return (m_vaoMap[ShapeType::square]);
    }
    }
    VertexArrayObject ShapeCreator::*createCircle(int anglesInDegrees){
      if(m_vaoMap.count(ShapeType::circle) >0 ){
        return (m_vaoMap[ShapeType::circle])(anglesInDegrees);
    }

    int vertexCount = 360/anglesInDegrees ;
    int triangleCount = anglesInDegrees -2;

    Vertex* vertexList = new Vertex[vertexCount];
    for(int i = 0; i < vertexCount; i++){
      float currentAngle = i*anglesInDegrees;
      float radius = 0.5f;

      vertex.position.x = radius*glm::cos(glm::radians(currentAngle));
      vertex.position.y = radius*glm::sin(glm::radians(currentAngle));
      vertex.position.z = 0.0f;

      vertex.texture.s = 0.5+0.5*glm::cos(glm::radians(currentAngle));
      vertex.texture.t = 0.5+0.5*glm::sin(glm::radians(currentAngle));
    }
    std::vector<unsigned int> indices;

    for(int i = 0; i < anglesInDegrees; i++){
      indices.push_back(0);
      indices.push_back(i+1);
      indices.push_back(i+2);
    }
    unsigned int


}