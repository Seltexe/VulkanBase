cmake_minimum_required(VERSION 4.2)
project(VulkanApp)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(VulkanApp ${MY_SOURCES})
target_include_directories(VulkanApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# ONLY CHANGE IF YOU HAVE A CLUE OF WHAT YOU ARE DOING
###########################################################
# SHIPING ONLY
#target_compile_definitions(${PROJECT_NAME}
#    PRIVATE RESOURCE_PATH="${CMAKE_BINARY_DIR}../resources"
#)
###########################################################
# PRODUCTION ONLY
target_compile_definitions(${PROJECT_NAME}
        PRIVATE RESOURCE_PATH="${CMAKE_SOURCE_DIR}/resources"
)
###########################################################

target_link_libraries(VulkanApp PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm
)