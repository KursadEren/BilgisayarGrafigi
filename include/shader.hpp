#ifndef shader_hpp
#define shader_hpp

#include <string>
#include <glm/glm.hpp>
#include<unordered_map>
using namespace std;

namespace Graph
{
    class Shader
    {
    public:
        void create();
        void attachShader(const string& fileName, unsigned int shaderType);
        void link();
        void use();
        void addUniform(const string& varName);
        void setVec3(const string& varname,const glm::vec3& value);
        void setVec4(const string& varname,const glm::vec4& value);
        void setFloat(const string& varname,float value);
    private:
        unsigned int m_id;
        string getShaderFromFile(const string& path);
        unordered_map<string, int> m_uniforms;
    };
}

#endif