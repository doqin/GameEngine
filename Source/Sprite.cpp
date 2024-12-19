#include "Sprite.h"
#include "SDL2/SDL_image.h"

Sprite::Sprite() {
    // Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mAlpha = 255;
}

Sprite::~Sprite() {
    // Deallocate
    free();
}

bool Sprite::loadFromFile(SDL_Renderer* mRenderer, const std::string& path) {
    // Get rid of preexisting texture
    free();

    // The final texture
    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    if (SDL_Surface* loadedSurface = IMG_Load(path.c_str()); loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else {
        // Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));

        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else {
            // Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        // Ged rif of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

void Sprite::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
        mAlpha = 0;
    }
}

void Sprite::setColor(Uint8 red, Uint8 green, Uint8 blue) const {
    // Modulate texture
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Sprite::setBlendMode(SDL_BlendMode blending) const {
    // Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void Sprite::setAlpha(Uint8 alpha) {
    // Set alpha value
    mAlpha = alpha;

    // Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Sprite::render(SDL_Renderer* mRenderer, int x, int y, const SDL_Rect* dstrect, const SDL_Rect* clip, double angle,
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

void Sprite::render(SDL_Renderer* mRenderer, int x, int y, int w, int h, const SDL_Rect* clip, double angle,
    const SDL_Point* center, SDL_RendererFlip flip) const {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = renderQuad = { x, y, w, h };

    //Render to screen
    SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void Sprite::render(SDL_Renderer* mRenderer, Uint8 alpha, int x, int y, const SDL_Rect* clip, double angle,
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

int Sprite::getWidth() const {
    return mWidth;
}

int Sprite::getHeight() const {
    return mHeight;
}