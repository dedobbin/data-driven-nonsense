#include <iostream>
#include <dirent.h>
#include "visuals.hpp"

Sprite::Sprite(SDL_Rect src, SDL_Rect pos, SDL_Texture* texture)
:src(src), pos(pos), texture(texture)
{}

Sprite::~Sprite()
{
	//Spritesheets are freed so in visuals, so don't free here
	//SDL_DestroyTexture(texture);
}

Visuals::Visuals()
{
	if (!initSDL()){
		exit(1);
	}

	loadSpritesheets("./assets/spritesheets");
}

Visuals::~Visuals()
{
	for (auto sprite : sprites){
		delete(sprite);
	}

	for (auto sheet : spritesheets){
		SDL_DestroyTexture(sheet.second);
	}
}

bool Visuals::loadSpritesheets(std::string path)
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (path.c_str())) != NULL) {
	while ((ent = readdir (dir)) != NULL) {
		if (strcmp(ent->d_name, ".") == 0 ^ strcmp(ent->d_name, "..") == 0){
			continue;
		}
		//std::string name = ent->d_name;
		spritesheets[ent->d_name] = loadTexture(path + "/" + ent->d_name);
	}

	closedir (dir);
	} else {
		std::cerr << "Can't load spritesheets " << strerror(errno) << std::endl;
		return false;
	}

}

bool Visuals::initSDL()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		std::cerr << "Could not init SDL: " << SDL_GetError() << std::endl;	
		return false;
	}
	
	if (!createWindow("plat")){
		return false;
	}

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if( renderer == NULL ){
		std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;	
		return false;
	}

	//SDL_SetRenderDrawColor( _r, 0xFF, 0xFF, 0xFF, 0xFF );
	if (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) < 0){
		std::cerr << "Could not set blend mode: " << SDL_GetError() << std::endl;	
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ){
		std::cerr << "Could not init SDL_image: " << SDL_GetError() << std::endl;	
		return false;
	}
	if( TTF_Init() == -1 ){
		std::cerr << "Could not init SDL_font: " << SDL_GetError() << std::endl;	
		return false;
	}
	font = TTF_OpenFont( "assets/OpenSans-Regular.ttf", 28 );
	if( font == NULL ){
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;	
        return false;
    }
	 //TODO: init sound
	 return true;
}

bool Visuals::createWindow(std::string title)
{
    window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            std::cerr <<  "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
            return false;
        }
	return true;
}

const int Visuals::renderText(std::string text, SDL_Color color, int x, int y, int h) const
{
	std::cerr << "TODO: implement render text" << std::endl;
	exit(1);
	// SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	// SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	// int textW = text.length() * getRelativeCharW(h);
	// SDL_Rect textRect = {x, y, textW, h};
	
	// SDL_RenderCopy(renderer, textTexture, NULL, &textRect); 
	// SDL_FreeSurface(textSurface);
	// SDL_DestroyTexture(textTexture);
	// return textW;		
}

SDL_Texture* Visuals::loadTexture( std::string path) const
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        std::cerr << sprintf("Graphics: Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else{
        // 0x64, 0x64, 0x64 is color that will be used for transparency because it's somewhat easy to remember
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x64, 0x64, 0x64));
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

        if (newTexture == NULL) {
            std::cerr << sprintf("Graphics: Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Visuals::render()
{
    SDL_SetRenderDrawColor( renderer, 148, 62, 62, 255 );
    SDL_RenderClear( renderer );

	for (auto sprite : sprites){
		//if (SDL_RenderCopyEx( renderer, sprite->texture, &sprite->src, &sprite->pos , NULL, NULL, sprite->flip) < 0){
		if (SDL_RenderCopy( renderer, sprite->texture, &sprite->src, &sprite->pos) < 0){
			std::cerr << "Failed to render sprite " << std::endl;
		}
	}

	SDL_RenderPresent(renderer);

}

int Visuals::addSprite(SDL_Rect src, SDL_Rect pos, std::string spritesheetName)
{
	SDL_Texture* spritesheet = spritesheets[spritesheetName];
	sprites.push_back(new Sprite(src, pos, spritesheet));
	return sprites.size() - 1;
}
		