#include "stx_window.hpp"

#include <stdexcept>

namespace stx
{
    Window::Window(int w, int h, std::string title)
    {
        this->width = w;
        this->height = h;
        this->title = title;
        initWindow();
    }

    Window::~Window()
    {
        glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR*surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface!");
        }
    }

    void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height)
    {
        auto stxWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        stxWindow->framebufferResized = true;
        stxWindow->width = width;
        stxWindow->height = height;
    }

    void Window::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(this->width, this->height, title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }
}