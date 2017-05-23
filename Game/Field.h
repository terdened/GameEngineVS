//
// Created by terde on 17.02.2017.
//

#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "GameObject.h"
#include "Cell.h"

using namespace GameEngine;

class Field : public GameObject {
public:
    Field(sf::RenderWindow& app): GameObject(app)
            { }
    void Update();
    void Init(ResourceManager* resourceManager);
private:
	shared_ptr<Cell> CreateCellForPosition(sf::RenderWindow& renderWindow, int x, int y);
	std::vector<shared_ptr<Cell>> cells;
	int ColumnsNumber;
	int RowsNumber;
};


#endif //GAME_FIELD_H
