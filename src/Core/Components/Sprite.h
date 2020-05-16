#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <iostream>
#include "../EntityManager.h"
#include "../Window.h"
#include "../../Render/Video.h"
#include "../../Core/Constants.h"
#include <glm.hpp>
#include <string>

class Sprite : public Component {
private:
	SDL_Texture* gTexture = NULL;

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

	string_const hash(std::string const& str) {
		if (str == "red") return string_const::red;
		if (str == "green") return string_const::green;
		if (str == "blue") return string_const::blue;
		if (str == "black") return string_const::black;
		if (str == "white") return string_const::white;
		return string_const::black;
	}

	void Init() override {
		loadResources();
	}

	bool loadResources() {
		bool success = true;

		gTexture = Video::loadTexture("Resources/DefaultSpritesheet.png");
		if (gTexture == NULL) {
			std::cerr << "Failed to load PNG image!" << std::endl;
			std::cout << "Failed to load PNG image!" << std::endl;
			success = false;
		}

		return success;
	}

	void Update(float deltaTime) override { }

	void Render() override {
		rect srcRect = { 0, 0, 1, 1 };
		rect destRect = { (int)position.x, (int)position.y, width, height };

		switch (hash(color)) {
		case string_const::red:
			srcRect = { 2, 0, 1, 1 };
			break;
		case string_const::green:
			srcRect = { 6, 0, 1, 1 };
			break;
		case string_const::blue:
			srcRect = { 11, 0, 1, 1 };
			break;
		case string_const::black:
			srcRect = { 0, 0, 1, 1 };
			break;
		case string_const::white:
			srcRect = { 4, 1, 1, 1 };
			break;
		}
		SDL_Rect r1 = Video::getRectangle(srcRect);
		SDL_Rect r2 = Video::getRectangle(destRect);
		SDL_Rect* p1 = &r1;
		SDL_Rect* p2 = &r2;

		// a pointer to a renderer(where you are going to renderize).
		// a pointer to a texture(where you are going to get the sprite).
		// pointer to source rect(the area and position where you get the sprite on the texture).
		// and pointer to dest rect(the area and position on the renderer you are going to draw).
		SDL_RenderCopy(Window::renderer, gTexture, p1, p2);
	}
};


#endif