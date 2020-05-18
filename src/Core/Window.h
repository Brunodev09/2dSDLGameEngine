#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>

#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"    

class Window {
private:
    bool isRunning;
public:
    Window();
    ~Window();
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static SDL_Surface* windowSurface;
    int lastFrameTicks;
    // const notation after signature makes this function unable to write to the pointer "this" of the class
    bool IsRunning() const;
    void load(int n);
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif