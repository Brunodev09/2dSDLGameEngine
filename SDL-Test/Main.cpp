#include "./Core/Constants.h"
#include "./Window.h"

int main(int argc, char* args[]) {
    
	Window *win = new Window();

	win->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (win->IsRunning()) {
        win->ProcessInput();
        win->Update();
        win->Render();
    }
    win->Destroy();

    return 0;
}