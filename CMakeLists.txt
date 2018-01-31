cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME
        "3dProject"
        )

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        main.cpp
        Objects/CollidableObject.cpp Objects/CollidableObject.h
        Objects/TestObject.cpp Objects/TestObject.h
        Coordinate.cpp Coordinate.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(SFML -lsfml-graphics -lsfml-window -lsfml-system)
set(GLU -lglut -lGLU -lGL)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${SFML} ${GLU})


include_directories(${OPENGL_INCLUDE_DIRS} ${SFML} ${GLU})
