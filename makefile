INIT_FILE=setup.cpp

PROJECT_NAME=SimplePlatformGame

COMPILER=g++

LIBS=-lraylib -lGL -lm -pthread -ldl

all:
	$(COMPILER) -o $(PROJECT_NAME) $(INIT_FILE) $(LIBS)
	./$(PROJECT_NAME)

clear:
	rm ./$(PROJECT_NAME)