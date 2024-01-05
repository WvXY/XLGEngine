#pragma once

#include "lge_window.hpp"
#include "lge_renderer.hpp"
#include "lge_device.hpp"
#include "lge_game_object.hpp"

#include <string>
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
        const std::string vertShaderPath = "shaders/simple_shader.vert.spv";
        const std::string fragShaderPath = "shaders/simple_shader.frag.spv";

        LgeWindow lgeWindow{"First App", WIDTH, HEIGHT};
        LgeDevice lgeDevice{lgeWindow};
        LgeRenderer lgeRenderer{lgeWindow, lgeDevice};

        void loadGameObjects();
        std::vector<LgeGameObject> gameObjects;
    };
}
