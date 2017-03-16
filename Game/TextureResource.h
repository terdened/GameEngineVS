//
// Created by terde on 22.02.2017.
//

#ifndef GAME_IMAGERESOURCE_H
#define GAME_IMAGERESOURCE_H


#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Resource.h"

namespace GameEngine {
    class TextureResource : public Resource {
    private:
        sf::Texture *texture;
    public:
        TextureResource(const unsigned int handle, const string &filename, const string &path,
                        const string &name = NULL) :
                Resource(handle, filename, path, name) {
            texture = new sf::Texture();
            if (!texture->loadFromFile(path + filename)) {
                std::cout << "Error during loading of texture resource " + path + filename + "\n";
                throw new std::exception;
            }

            std::cout << "Texture resource " + path + filename + " was successfully loaded" + "\n";
        }

        sf::Texture *Texture() {
            return texture;
        }

        ~TextureResource() {
            delete texture;
        }
    };
}


#endif //GAME_IMAGERESOURCE_H
