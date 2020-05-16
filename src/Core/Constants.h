#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const float FPS = 60.0f;
const float SECOND = 1000.0f;
// around 16ms per frame
const float FRAME_TIME_MS = 1000.0f / FPS;

enum class string_const {
	red,
	green,
	blue,
	black,
	white
};

struct rect {
	int x;
	int y;
	int w;
	int h;
};

#endif