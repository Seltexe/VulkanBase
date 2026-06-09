#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <stx_window.hpp>
#include "stx_pipeline.hpp"

namespace stx
{
    class Application
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
    private:
        Window window{WIDTH, HEIGHT, "HELLO VULKAN"};
        Pipeline pipeline{RESOURCE_PATH"/shaders/simple_shader.vert.spv", RESOURCE_PATH"/shaders/simple_shader.frag.spv"};
    };
}

#endif