#include <TileSet.h>
#include <iostream>

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) 
: tileWidth(tileWidth), tileHeight(tileHeight), tileCount(0) {

    tileSet.Open(file);

    if (tileSet.IsOpen()){
        int colunas = tileSet.GetWidth() / tileWidth;
        int linhas = tileSet.GetHeight() / tileHeight;

        tileCount = colunas * linhas;

        tileSet.SetFrameCount(colunas, linhas);
    }
}

void TileSet::RenderTile(unsigned index, float x, float y){
    if (index >= (unsigned)tileCount) {
        return;
    }

    tileSet.SetFrame(index);
    tileSet.Render(x, y, tileWidth, tileHeight);
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}