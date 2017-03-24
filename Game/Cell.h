//
// Created by terde on 13.02.2017.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "GameObject.h"
#include "ResourceManager.h"

using namespace GameEngine;

class Cell : public GameObject {
private:
    sf::Color GetColor(int value);
    shared_ptr<sf::RectangleShape> tile;
	void BrushInRed();
	void BrushInCellColor();
	void Move(int direction);
	void PlayMoveAnimation(int direction);
protected:
	void OnMouseOn();
	void OnMouseOff();
public:
    Cell(sf::RenderWindow& app): GameObject(app), value(512)
        { }
    void Update();
    void Init(ResourceManager* resourceManager);
	int PositionX;
	int PositionY;
	void SetCellPosition(int x, int y);
	int value;
};


#endif //GAME_CELL_H
