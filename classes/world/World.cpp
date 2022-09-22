#include <fstream>
#include <string>
#include <iostream>
#include <new>
#include "game/Consts.h"
#include "world/tilesTypes/Wall.h"
#include "world/tilesTypes/Floor.h"
#include "world/Tile.h"
#include "world/World.h"

World::World():
    mapSize(0),
    mapWidth(0)
{}

void World::construct(int level){
    this->loadMap();
    this->defineTilemap();
}

void World::loadMap(){
    int curSize = 5;
    this->levelData = new char[curSize];
    std::ifstream levelFile ("classes/world/Levels/level1.level");
    if ( levelFile.is_open() ) {
        int isFirst = 1;
        char mychar;
        while ( levelFile ) {
            mychar = levelFile.get();
            if(mychar == '\n' || mychar == EOF){
                if(isFirst){
                    isFirst = 0;
                    mapWidth = mapSize;
                }
                continue;
            }
            if(curSize <= mapSize){
                curSize*=2;
                levelData = (char*) realloc(
                    levelData,
                    curSize*sizeof(char)
                );
            }
            levelData[mapSize] = mychar;
            mapSize++;
        }
    }
}

void World::defineTilemap(){
    tilemap = new Tile[mapSize];
    for(int i = 0; i < mapSize; i++){
        Tile tile = defineTileType(levelData[i]);
        tilemap[i] = tile;
    }
}

Tile World::defineTileType(char type){
    Tile tile;
    switch (type)
    {
        case 'w': {
            Wall wallTile(0);
            tile = wallTile;
            break;
        }
        case 'f':{
            Floor floorTile(1);
            tile = floorTile;
            break;
        }
        default:
            break;
    }
    return tile;
}

void World::draw(){
    int rows = mapSize/mapWidth;
    for(int x = 0; x < mapWidth; x++){
        for(int y = 0; y < rows; y++){
            int indexFromCoordinates = y * mapWidth + x;
            Tile tile = tilemap[indexFromCoordinates];
            DrawTexturePro(
                tile.getTexture(), 
                tile.getSource(),
                Rectangle{
                    (float)x*tile.getWidth()*Consts::getScale(),
                    (float)y*tile.getHeight()*Consts::getScale(),
                    tile.getWidth()*Consts::getScale(),
                    tile.getHeight()*Consts::getScale()
                },
                (Vector2){
                    (float)tile.getWidth()/2,
                    (float)tile.getHeight()/2
                },
                0,
                WHITE
            );
        }
    }
}