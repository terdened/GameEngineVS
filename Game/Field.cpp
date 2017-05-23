//
// Created by terde on 17.02.2017.
//

#include "stdafx.h"
#include "Field.h"
#include "Cell.h"
#include "ResourceManager.h"


using namespace sf;

void Field::Update() {
    GameObject::Update();
    //Rotate(1);
}

void Field::Init(ResourceManager* resourceManager) {
	this->resourceManager = resourceManager;
	ColumnsNumber = 5;
	RowsNumber = 7;

	auto tile = std::make_shared<RectangleShape>();
	Vector2f size(5 * 100, 7 * 100);
	tile->setSize(size);
	tile->setFillColor(Color(128, 128, 128));
	AddShape(tile);

	SetPivotPoint(Vector2f(250, 250));

	for (int i = 0; i < RowsNumber; i++) {
		for (int j = 0; j < ColumnsNumber; j++) {
			auto cell = CreateCellForPosition(renderWindow, j, i);
			cells.push_back(cell);
			AddChild(cell);
		}
	}
}

shared_ptr<Cell> Field::CreateCellForPosition(sf::RenderWindow& renderWindow, int x, int y) {
	auto cell = std::make_shared<Cell>(renderWindow);
	cell->SetCellPosition(x, y);
	return cell;
}