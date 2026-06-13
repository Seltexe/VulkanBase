#ifndef STX_WINDOW_H
#define STX_WINDOW_H
#include <string>
#include <memory>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

namespace stx
{
    class Window
    {
    public:
        Window(int w, int h, std::string title);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        inline bool shouldClose() {return glfwWindowShouldClose(window);}
        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
        bool wasWindowResized() { return framebufferResized; }
        void resetWindowResizedFlag() { framebufferResized = false; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:
        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
        void initWindow();

        GLFWwindow* window;
        std::string title;

        int width;
        int height;
        bool framebufferResized = false;

    };
}

#endif