//
// Created by terde on 13.02.2017.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "GameObject.h"
#include "ResourceManager.h"

using namespace gameengine;

class Cell : public GameObject {
private:
    int value;
    sf::Color GetColor(int value);
    shared_ptr<sf::RectangleShape> tile;
	void BrushInRed();
	void BrushInCellColor();
protected:
	void OnMouseOn();
	void OnMouseOff();
public:
    Cell(sf::RenderWindow& app): GameObject(app), value(512)
        { }
    void Update();
    void Init(ResourceManager* resourceManager);
};


#endif //GAME_CELL_H
