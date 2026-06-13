#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "stx_pipeline.hpp"
#include "stx_swap_chain.hpp"
#include "stx_window.hpp"
#include "stx_model.hpp"

// std
#include <memory>
#include <vector>

namespace stx
{
    class Application
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        Application();
        ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;

        void run();
    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        void sierpinski(std::vector<Model::Vertex> &vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);

        Window window{WIDTH, HEIGHT, "HELLO VULKAN"};
        Device device{window};
        SwapChain swapChain{device, window.getExtent()};
        std::unique_ptr<Pipeline> pipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<Model> model;

    };
}

#endif