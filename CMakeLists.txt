cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)

include(CMakePrintHelpers)  #cmake_print_variable   fonksiyonu için

#proje ismi ayarlanıyor.
string(FIND ${CMAKE_CURRENT_SOURCE_DIR} / BaslangicIndeks REVERSE)
math(EXPR BaslangicIndeks "${BaslangicIndeks}+1")
string(SUBSTRING ${CMAKE_CURRENT_SOURCE_DIR} ${BaslangicIndeks} -1 ProjeIsmi)

#proje ismi belirleniyor
project(${ProjeIsmi})

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )

add_subdirectory( glfw )

option( ${ProjeIsmi}-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

if( ${ProjeIsmi}-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
endif()

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

#proje klasörünün yolu yeni bir değişkene atanıyor
set(Project_Dir ${CMAKE_SOURCE_DIR})

set(Kutuphane_Dir ${Project_Dir}/libs)

#inlcude ve src klasör yollarıda yeni bir değişkene atanıyor
set(Project_Include_Dir ${Project_Dir}/include)

set(Project_Src_Dir ${Project_Dir}/src)

#Kaynak Dosyalari ekleniyor
set(Project_Source_Files 
            ${Project_Src_Dir}/main.cpp
            ${Project_Src_Dir}/glad.c
            ${Project_Src_Dir}/shader.cpp
            ${Project_Src_Dir}/vertexbuffer.cpp
        ${Project_Src_Dir}/vertexarrayobject.cpp
        ${Project_Src_Dir}/texturemanager.cpp
            ${Project_Src_Dir}/GLWindow.cpp
        include/indexbuffer.hpp src/indexbuffer.cpp)

include_directories(
    ${Project_Include_Dir}
    glm
    stb)

add_executable( ${ProjeIsmi} WIN32 ${Project_Source_Files} ${GLAD_GL} )

target_link_libraries( ${ProjeIsmi} ${OPENGL_LIBRARIES} glfw )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set '${ProjeIsmi}' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${ProjeIsmi} )
    endif()
endif()