//
// Created by terde on 19.02.2017.
//

#ifndef GAME_FONTRESOURCE_H
#define GAME_FONTRESOURCE_H


#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <memory>
#include "Resource.h"

namespace GameEngine {
    class FontResource : public Resource {
    private:
        sf::Font* font;
    public:
        FontResource(const unsigned int handle, const string& filename, const string& path, const string& name = NULL):
                Resource(handle, filename, path, name) {
            font = new sf::Font();
            if (!font->loadFromFile(path+filename)) {
                std::cout << "Error during loading of font resource " +path + filename + "\n";
                throw new std::exception;
            }

            std::cout << "Font resource " +path + filename + " was successfully loaded" + "\n";
        }

        sf::Font* Font() {
            return font;
        }

        ~FontResource() {
            delete font;
        }
    };
}

#endif //GAME_FONTRESOURCE_H
