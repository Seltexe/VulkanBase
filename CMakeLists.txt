cmake_minimum_required(VERSION 4.2)
project(VulkanBase)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(VulkanApp ${MY_SOURCES})

target_link_libraries(VulkanApp PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm
)