#include <TileMap.h>
#include <GameObject.h>
#include <fstream>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet)
: Component(associated), tileSet(nullptr), mapWidth(0), mapHeight(0), mapDepth(0){
    Load(file);
    SetTileSet(tileSet);
}

void TileMap::Load(std::string file){
    std::ifstream mapFile(file);

    if (!mapFile.is_open()){
        return;
    }

    char comma;

    mapFile >> mapWidth >> comma;
    mapFile >> mapHeight >> comma;
    mapFile >> mapDepth >> comma;

    tileMatrix.resize(mapWidth * mapHeight * mapDepth);

    for (int z = 0; z < mapDepth; z++) {
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                mapFile >> At(x, y, z);
                mapFile >> comma;
            }
        }
    }

    mapFile.close();
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet.reset(tileSet);
}

int& TileMap::At(int x, int y, int z){
    return tileMatrix[x + y * mapWidth + z * mapWidth * mapHeight];
}

void TileMap::RenderLayer(int layer){
    if (layer < 0 || layer >= mapDepth) {
        return;
    }

    if (tileSet == nullptr) {
        return;
    }

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {

            int tile = At(x, y, layer);

            if (tile >= 0) {
                float posX = associated.box.x + x * tileSet->GetTileWidth();

                float posY = associated.box.y + y * tileSet->GetTileHeight();

                tileSet->RenderTile(tile, posX, posY);
            }
        }
    }
}

void TileMap::Render(){
    for(int z = 0; z < mapDepth; z++){
        RenderLayer(z);
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

void TileMap::Update(float dt){   
}