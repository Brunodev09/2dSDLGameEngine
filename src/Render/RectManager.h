#ifndef RECTMANAGER_H
#define RECTMANAGER_H

#include <SDL.h>

class RectManager {
public:
    RectManager(SDL_Rect* rectangle) : _rectangle(rectangle) { }
    ~RectManager() { delete _rectangle; }

    SDL_Rect* instance() const { return _rectangle; }

private:
    SDL_Rect* _rectangle;
};

#endif

