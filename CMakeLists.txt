cmake_minimum_required(VERSION 3.21)
project(OGL)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

FetchContent_Declare(
        assimp
        GIT_REPOSITORY https://github.com/assimp/assimp.git
        GIT_TAG        v5.2.3
)
set(assimp_BUILD_TESTS OFF)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0.9.9.8
)
FetchContent_Declare(
        glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.6
)
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.87
)
FetchContent_MakeAvailable(assimp glm glfw3 imgui)
find_library(glfw ${glfw3_BUILD_DIR}/src)

set(imgui_src  ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp)

add_executable(OGL src/main.cpp
        src/glad.c
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp)
target_link_libraries(OGL PRIVATE assimp glm::glm glfw )



include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/glad
        ${CMAKE_SOURCE_DIR}/include/KHR/
        ${CMAKE_SOURCE_DIR}/include/imgui
        ${assimp_SOURCE_DIR}/include/assimp
        ${glm_SOURCE_DIR}/glm
        ${glfw3_SOURCE_DIR}/include/GLFW
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends)