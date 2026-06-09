#include "application.hpp"

namespace stx
{
    void Application::run()
    {
        while (!window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}