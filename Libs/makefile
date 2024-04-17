

# all:
# 	g++ main.cpp -o appmain -I./include/SDL2 -L./lib -lmingw32 -lSDL2main -lSDL2

PROJECTNAME = game_with_sdl
OUTPUT_DIR = build

# INCLUDE_DIRS = -I./include/SDL2 -I./include/others   #multiple includes
INCLUDE_DIRS = -I./include/SDL2
LIBS_DIRS = -Llib

LIBS = -lmingw32 -lSDL2main -lSDL2

SRC = $(wildcard src/*.cpp)  # $(wildcard  imgui/*.cpp) example of additional sources

default:
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME) $(INCLUDE_DIRS) $(LIBS_DIRS) $(LIBS)