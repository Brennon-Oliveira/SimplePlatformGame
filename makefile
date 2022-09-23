INIT_FILE=setup.cpp

PROJECT_NAME=SimplePlatformGame

INCLUDES=classes/game/TextureLoader.cpp classes/entities/Player.cpp classes/world/World.cpp classes/world/Tile.cpp classes/world/tilesTypes/Floor.cpp classes/game/Game.cpp classes/world/tilesTypes/Wall.cpp 

COMPILER=g++

LIBS=-lraylib -lGL -lm -pthread -ldl

all:
	$(COMPILER) -o $(PROJECT_NAME) -Iinclude $(INCLUDES) $(INIT_FILE) $(LIBS)
	./$(PROJECT_NAME)

clear:
	rm ./$(PROJECT_NAME)
