
#include "game/TextureLoader.h"

Texture2D TextureLoader::floorTexture;
Texture2D TextureLoader::wallTexture;

void TextureLoader::loadTextures(){
    TextureLoader::wallTexture = LoadTexture("./assets/Background/Yellow.png");
    TextureLoader::floorTexture = LoadTexture("./assets/Terrain/Terrain.png");
}
