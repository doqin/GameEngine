#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>

class Text {
public:
    // Initializes variables
    Text();
    // Deallocates memory
    ~Text();

    // Creates image from font string
    bool loadFromRenderedText(SDL_Renderer* mRenderer, TTF_Font* mFont, const std::string& textureText, SDL_Color textColor);

    // Deallocates texture
    void free();

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue) const;

    // Set blending
    void setBlendMode(SDL_BlendMode blending) const;

    // Set alpha modulation
    void setAlpha(Uint8 alpha);

    // Renders texture at given point
    void render(SDL_Renderer* mRenderer, int x, int y, const SDL_Rect* dstrect = nullptr, const SDL_Rect* clip = nullptr,
        double angle = 0.0, const SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    void render(SDL_Renderer* mRenderer, int x, int y, int w, int h, const SDL_Rect* clip = nullptr, double angle = 0.0,
        const SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    void render(SDL_Renderer* mRenderer, Uint8 alpha, int x, int y, const SDL_Rect* clip = nullptr, double angle = 0.0,
        const SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    //Gets image dimensions
    int getWidth() const;
    int getHeight() const;

private:
    // The actual hardware texture
    SDL_Texture* mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;
    Uint8 mAlpha;
};

