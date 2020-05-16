#ifndef VIDEO_H
#define VIDEO_H

#include "../Core/Window.h"
#include "./RectManager.h"
#include "../Core/Constants.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Video {
public:
	static SDL_Texture* loadTexture(std::string path) {
		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL) {
			std::cerr << "Failed to load PNG image!" << std::endl;
			std::cerr << IMG_GetError() << std::endl;
			std::cout << IMG_GetError() << std::endl;
		}
		else {
			newTexture = SDL_CreateTextureFromSurface(Window::renderer, loadedSurface);
			if (newTexture == NULL) {
				std::cerr << "Unable to generate texture! SDL Error!" << std::endl;
				std::cerr << SDL_GetError() << std::endl;
				std::cout << "Unable to generate texture! SDL Error!" << std::endl;
				std::cout << SDL_GetError() << std::endl;
			}
			SDL_FreeSurface(loadedSurface);
		}
		return newTexture;
	}

	static SDL_Rect getRectangle(int x, int y, int w, int h) {
		return SDL_Rect { x, y, w, h };
	}

	static SDL_Rect getRectangle(rect r) {
		return SDL_Rect{ r.x, r.y, r.w, r.h };
	}

	static SDL_Rect* getRectangleRaw(rect r) {
		RectManager rectManager(new SDL_Rect{ r.x, r.y, r.w, r.h });
	}

};

#endif