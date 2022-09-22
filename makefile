INIT_FILE=setup.cpp

PROJECT_NAME=SimplePlatformGame

COMPILER=g++

LIBS=-lraylib -lGL -lm -pthread -ldl

all:
	$(COMPILER) -o $(PROJECT_NAME) $(INIT_FILE) $(LIBS)
	./$(PROJECT_NAME)

clear:
	rm ./$(PROJECT_NAME)

#g++ -o SimplePlatformGame -Iinclude classes/entities/Player.cpp classes/world/World.cpp classes/world/Tile.cpp classes/world/tilesTypes/Floor.cpp classes/world/tilesTypes/Wall.cpp classes/game/Game.cpp classes/game/Consts.cpp setup.cpp  -lraylib -lGL -lm -pthread -ldl