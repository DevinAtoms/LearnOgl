cmake_minimum_required(VERSION 3.21)
project(OGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MAKE_PROGRAM ninja)
include(FetchContent)
include(ExternalProject)
find_package(OpenGL)

add_library(mod src/glad.c src/gui.cpp)

set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(assimp GIT_REPOSITORY https://github.com/assimp/assimp.git GIT_TAG v5.2.3)
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 0.9.9.8)
FetchContent_Declare(glfw3 GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.6)
FetchContent_Declare(imgui GIT_REPOSITORY https://github.com/ocornut/imgui.git GIT_TAG v1.87)

FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
    set(IMGUI_INCLUDE_DIR ${imgui_SOURCE_DIR}/)
    file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
    file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
    add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_SOURCES} ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
            ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
    add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
    target_include_directories(imgui PUBLIC ${imgui_INCLUDE_DIR} ${glfw_INCLUDE_DIR})
    target_link_libraries(imgui glfw)
endif()

FetchContent_MakeAvailable(glfw3 glm assimp imgui)
find_package(Bullet REQUIRED)

target_link_libraries(mod imgui glfw glm assimp dl OpenGL ${BULLET_LIBRARIES})


add_executable(OGL src/main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/glad ${CMAKE_SOURCE_DIR}/include/KHR/
        ${assimp_SOURCE_DIR}/include/assimp ${glm_SOURCE_DIR}/glm ${glfw3_SOURCE_DIR}/include/GLFW ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends ${bullet_SOURCE_DIR}/include ${BULLET_INCLUDE_DIR})

target_link_libraries(OGL mod)
