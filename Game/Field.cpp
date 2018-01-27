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
    this->resource_manager = resourceManager;
    auto tile = std::make_shared<RectangleShape>();
    Vector2f size(500, 500);
    tile->setSize(size);
    tile->setFillColor(Color(128, 128, 128));
    AddShape(tile);

    SetPivotPoint(Vector2f(250, 250));

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            auto cell = std::make_shared<Cell>(render_window);
            cell->SetPosition(sf::Vector2f(j*100, i*100));
            AddChild(cell);
        }
    }
}