#ifndef STX_WINDOW_H
#define STX_WINDOW_H
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

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:
        void initWindow();

        GLFWwindow* window;
        std::string title;

        int width;
        int height;
    };
}

#endif