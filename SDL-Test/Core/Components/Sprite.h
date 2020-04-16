#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <iostream>
#include "../EntityManager.h"
#include "../../Window.h"
#include <glm.hpp>
#include <string>

class Sprite : public Component {
private:
    SDL_Surface* gSprite = NULL;

public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;
    std::string color;

    Sprite(int pX, int pY, int vX, int vY, int w, int h, int s, std::string c) {
        position = glm::vec2(pX, pY);
        velocity = glm::vec2(vX, vY);
        width = w;
        height = h;
        scale = s;
        color = c;
    }

    void Init() override {
        loadResources();
    }

    bool loadResources() {
        bool success = true;

        gSprite = loadSurface("Resources/DefaultSpritesheet.png");
        if (gSprite == NULL) {
            std::cerr << "Failed to load PNG image!" << std::endl;
            success = false;
        }
        
        return success;
    }

    SDL_Surface* loadSurface(std::string path) {
        SDL_Surface* optimizedSurface = NULL;

        SDL_Surface* loadedSurface = IMG_Load(path.c_str());
        if (loadedSurface == NULL) {
            std::cerr << "Unable to load image! SDL_image Error" << std::endl;
            std::cerr << IMG_GetError() << std::endl;
        }
        else {
            optimizedSurface = SDL_ConvertSurface(loadedSurface, Window::windowSurface->format, 0);
            if (optimizedSurface == NULL) {
                std::cerr << "Unable to optimize image! SDL Error!" << std::endl;
                std::cerr << SDL_GetError() << std::endl;
            }

            SDL_FreeSurface(loadedSurface);
        }

        return optimizedSurface;
    }

    void Update(float deltaTime) override { }

    void Render() override {
        SDL_BlitSurface(gSprite, NULL, Window::windowSurface, NULL);
        SDL_UpdateWindowSurface(Window::window);
    }
};


#endif