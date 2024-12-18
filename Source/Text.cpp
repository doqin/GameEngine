#include "Text.h"

Text::Text() {
    // Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mAlpha = 255;
}

Text::~Text() {
    // Deallocate
    free();
}

bool Text::loadFromRenderedText(SDL_Renderer* mRenderer, TTF_Font* mFont, const std::string& textureText, const SDL_Color textColor) {
    // Get rid of preexisting texture
    free();

    // Render text surface
    if (SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, textureText.c_str(), textColor); textSurface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else {
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
        if (mTexture == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else {
            // Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        // Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    // Return success
    return mTexture != nullptr;
}

void Text::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
        mAlpha = 0;
    }
}

void Text::setColor(Uint8 red, Uint8 green, Uint8 blue) const {
    // Modulate texture
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Text::setBlendMode(SDL_BlendMode blending) const {
    // Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void Text::setAlpha(Uint8 alpha) {
    // Set alpha value
    mAlpha = alpha;

    // Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Text::render(SDL_Renderer* mRenderer, int x, int y, const SDL_Rect* dstrect, const SDL_Rect* clip, double angle,
    const SDL_Point* center, SDL_RendererFlip flip) const {
    // Set rendering space and render to screen
    SDL_Rect renderQuad;
    if (dstrect == nullptr) {
        renderQuad = { x, y, mWidth, mHeight };
    }
    else {
        renderQuad = *dstrect;
    }
    // Set clip rendering dimensions
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // Render to screen
    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void Text::render(SDL_Renderer* mRenderer, int x, int y, int w, int h, const SDL_Rect* clip, double angle,
    const SDL_Point* center, SDL_RendererFlip flip) const {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = renderQuad = { x, y, w, h };

    //Render to screen
    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void Text::render(SDL_Renderer* mRenderer, Uint8 alpha, int x, int y, const SDL_Rect* clip, double angle,
    const SDL_Point* center, SDL_RendererFlip flip) const {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_SetTextureAlphaMod(mTexture, alpha);
    //Render to screen
    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
    SDL_SetTextureAlphaMod(mTexture, mAlpha);
}

int Text::getWidth() const {
    return mWidth;
}

int Text::getHeight() const {
    return mHeight;
}