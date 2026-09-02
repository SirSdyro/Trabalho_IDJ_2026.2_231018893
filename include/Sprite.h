#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
using namespace std;

class Sprite{
    public:
        Sprite();
        Sprite(string file, int frameCountW = 1, int frameCountH = 1);
        ~Sprite();

        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y, int w, int h);
        void SetFrame(int frame);
        void SetFrameCount(int frameCountW, int frameCountH);

        int GetWidth();
        int GetHeight();
        bool IsOpen();
    private:
        SDL_Texture* texture;
        int width;
        int height;
        int frameCountW;
        int frameCountH;
        SDL_Rect clipRect;
};

#endif