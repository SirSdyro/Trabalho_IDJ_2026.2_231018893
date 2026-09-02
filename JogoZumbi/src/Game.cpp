#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <Game.h>
#include <Resources.h>
using namespace std;

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(instance != nullptr){
        throw std::runtime_error("Game ja possui uma instancia.");
    }

    instance = this;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        cout << "Erro ao carregar janela: " << SDL_GetError() << endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    if(renderer == nullptr){
        cout << "Erro ao carregar renderizador: " << SDL_GetError() << endl;
        return;
    }
    
    state = new State();
}

Game::~Game(){
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game& Game::GetInstance(){
    if(instance != nullptr){
        return *instance;
    }
    else{
        instance = new Game("João Henrique Jácomo Lemes - 231018893", 1200, 900);

        return *instance;
    }
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while(not GetState().QuitResquested()){
        GetState().Update(0);
        GetState().Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}