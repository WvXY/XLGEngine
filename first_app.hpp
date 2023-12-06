#pragma once

#include "lge_window.hpp"
#include "lge_pipeline.hpp"
#include "lge_swap_chain.hpp"
#include "lge_device.hpp"

#include <string>
#include <filesystem>
#include <memory>
#include <vector>

namespace lge {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1280;
        static constexpr int HEIGHT = 720;

        FirstApp();

        ~FirstApp();

        FirstApp(const FirstApp &) = delete;

        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        const std::string rootPath = std::filesystem::current_path().parent_path().string();
        const std::string vertShaderPath = "\\shaders\\simple_shader.vert.spv";
        const std::string fragShaderPath = "\\shaders\\simple_shader.frag.spv";

        void createPipelineLayout();

        void createPipeline();

        void createCommandBuffers();

        void drawFrame();

        LgeWindow lgeWindow{"First App", WIDTH, HEIGHT};
        LgeDevice lgeDevice{lgeWindow};
        LgeSwapChain lgeSwapChain{lgeDevice, lgeWindow.getExtent()};
        std::unique_ptr<LgePipeline> lgePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;

    };
}