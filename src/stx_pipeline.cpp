#include "stx_pipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace stx
{
    Pipeline::Pipeline(Device& device,
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo) : device(device)
    {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }

    std::vector<char> Pipeline::readFile(const std::string& filepath)
    {
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);

        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void Pipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath, const PipelineConfigInfo& configInfo)
    {
        auto vertShader = readFile(vertFilepath);
        auto fragShader = readFile(fragFilepath);

        std::cout << "Vertex shader code size: " << vertShader.size() << std::endl;
        std::cout << "Fragment shader code size: " << fragShader.size() << std::endl;
    }

    void Pipeline::createShaderModule(const std::vector<char> &code, VkShaderModule*configInfo)
    {
        VkShaderModuleCreateInfo createInfo{};
    }
}
