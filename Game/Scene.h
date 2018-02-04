//
// Created by terde on 15.02.2017.
//

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <SFML/Graphics.hpp>
#include "game-object.h"
#include "resource-loader.h"
#include "silhouette.h"

using namespace std;

namespace gameengine {
    class Scene {
    private:
		vector<shared_ptr<GameObject>> childs;
    protected:
        ResourceManager* resource_manager;
        sf::RenderWindow& render_window;
        ResourceLoader* resource_loader;
    public:
        Scene(sf::RenderWindow& app): render_window(app)
                { }
        void Draw();
        virtual void Update();
        virtual void Init() = 0;
        void AddChild(shared_ptr<GameObject> child);
    };
}


#endif //GAME_SCENE_H
