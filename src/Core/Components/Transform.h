#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../EntityManager.h"
#include "../Window.h"
#include "../../Render/Video.h"
#include <glm.hpp>
#include <SDL.h>

class Transform : public Component {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    Transform(int pX, int pY, int vX, int vY, int w, int h, int s) {
        position = glm::vec2(pX, pY);
        velocity = glm::vec2(vX, vY);
        width = w;
        height = h;
        scale = s;
    }

    void Init() override {

    }

    void Update(float deltaTime) override {
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    }

    void Render() override {
        SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
        SDL_Rect r = Video::getRectangle((int)position.x, (int)position.y, width, height);
        SDL_Rect* rectangle = &r;
        SDL_RenderFillRect(Window::renderer, rectangle);
    }
};


#endif