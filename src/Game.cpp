#include <iostream>
#include "./Game.h"
#include "./Constants.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game() { this->isRunning = false; }

Game::~Game() {}

bool Game::IsRunning() const { return this->isRunning; }

void Game::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error loading SDL." << std::endl;
        return;
    }
    window =
        SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         width, height, SDL_WINDOW_BORDERLESS);

    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    // According to SDL API docs -1 sets the default monitor driver
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    isRunning = true;
    return;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
        default:
            break;
    }
}

void Game::Update() {

    while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTicks + FRAME_TIME_MS));

    float deltaTime = (SDL_GetTicks() - lastFrameTicks) / SECOND;

    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    lastFrameTicks = SDL_GetTicks();
}

void Game::Render() {
    // SDL works with double buffers (front and back) to avoid flickering and
    // other weird stuff It avoids it by swapping the rendered pixels between
    // the buffers instead of re-rendering This will clear the back buffer
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);


    // This is actually going to swap the buffers
    // Please don't forget this again...can't stand to keep crashing
    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
