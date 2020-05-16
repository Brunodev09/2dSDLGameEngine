OBJS = *.cpp Core/*.cpp Core/Components/*.h Render/*.h API/Templates/*.cpp

CC = g++

INCLUDE_PATHS = -IC:\vs_dev_libs\SDL\include\SDL2 -IC:\vs_dev_libs\glm

LIBRARY_PATHS = -LC:\vs_dev_libs\SDL\lib

# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

OBJ_NAME = Main

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	del Main.exe
 
run:
	Main.exe