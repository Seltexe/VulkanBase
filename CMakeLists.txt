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

# --- Shader compilation ---
find_program(GLSLC glslc REQUIRED)

file(GLOB_RECURSE GLSL_SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/resources/shaders/*.vert"
        "${CMAKE_SOURCE_DIR}/resources/shaders/*.frag"
        "${CMAKE_SOURCE_DIR}/resources/shaders/*.comp"
)

foreach(GLSL ${GLSL_SOURCE_FILES})
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${CMAKE_SOURCE_DIR}/resources/shaders/${FILE_NAME}.spv")
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${GLSLC} ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL}
    )
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach()

add_custom_target(Shaders DEPENDS ${SPIRV_BINARY_FILES})
add_dependencies(VulkanApp Shaders)