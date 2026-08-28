//Use mingw32-make para usar o arquivo make e compilar o main.cpp
//Use ./main para executar

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <Game.h>

//width = 1200, height = 900
const int width = 1200, height = 900;

/*int main( int argc, char** argv){
    SDL_Init( SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("João Henrique Jácomo Lemes - 231018893", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window){
        std::cout << "erro" << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    while (true)
    {
        if ( SDL_PollEvent( &windowEvent )){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
    
}*/

int main(int argc, char** argv)
{
    Game& game = Game::GetInstance();

    game.Run();

    return 0;
}