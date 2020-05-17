cmake_minimum_required(VERSION 3.7)

project(bdv-engine)

set(SOURCES
    src/Main.cpp
    src/Bdv.cpp
    src/Script.h
    src/Core/Window.cpp
    src/Core/DebugHelper.h
    src/Core/Component.h
    src/Core/Constants.h
    src/Core/Entity.cpp
    src/Core/EntityManager.cpp
    src/Core/Components/Sprite.h
    src/Core/Components/Transform.h
    src/Render/RectManager.h
    src/Render/Video.h
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -lSDL2main -lSDL2 -lSDL2_image)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_DIRS})

target_link_libraries(bdv-engine ${SDL2_LIBRARIES})