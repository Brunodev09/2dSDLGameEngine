#include <iostream>
#include "./Window.h"
#include "./Core/Constants.h"
#include "./Core/Components/Transform.h"
#include "./Core/Components/Sprite.h"
#include <glm.hpp>

EntityManager manager;
SDL_Renderer* Window::renderer;
SDL_Window* Window::window;
SDL_Surface* Window::windowSurface;

Window::Window() { this->isRunning = false; }

Window::~Window() {}

bool Window::IsRunning() const { return this->isRunning; }

void Window::Initialize(int width, int height) {
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

	// Initializing SDL_image
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cerr << IMG_GetError() << std::endl;
		return;
	}
	else {
		windowSurface = SDL_GetWindowSurface(window);
	}

	load(0);

	isRunning = true;
	return;
}

void Window::load(int n) {
	Entity& newE(manager.AddEntity("square_1"));
	//newE.AddComponent<Transform>(0, 0, 20, 20, 32, 32, 1);
	newE.AddComponent<Sprite>(0, 0, 20, 20, 32, 32, 1, "red");
	manager.ListAllEntities();
}

void Window::ProcessInput() {
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

void Window::Update() {

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastFrameTicks + FRAME_TIME_MS));

	float deltaTime = (SDL_GetTicks() - lastFrameTicks) / SECOND;

	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

	lastFrameTicks = SDL_GetTicks();

	manager.Update(deltaTime);
}

void Window::Render() {
	// SDL works with double buffers (front and back) to avoid flickering and
	// other weird stuff It avoids it by swapping the rendered pixels between
	// the buffers instead of re-rendering This will clear the back buffer
	// SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	// SDL_RenderClear(renderer);

	if (manager.hasNoEntities()) return;
	manager.Render();

	// This is actually going to swap the buffers
	//SDL_RenderPresent(renderer);
}

void Window::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}