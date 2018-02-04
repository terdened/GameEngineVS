//
// Created by terde on 13.02.2017.
//

#include "stdafx.h"
#include "cell.h"
#include "rectangular-silhouette.h"
#include "tile-animation-controller.h"
#include <sstream>

using namespace sf;

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm;
    stm << n ;
    return stm.str();
}

void Cell::Update() {
    GameObject::Update();        
}

void Cell::Init(ResourceManager* resource_manager) {
    this->resource_manager = resource_manager;
	animation_controller = new TileAnimationController();

    tile = std::make_shared<RectangleShape>();
    tile->setPosition(3, 3);
    Vector2f size(94, 94);
    tile->setSize(size);
    tile->setFillColor(GetColor(value));
    AddShape(tile);
    SetPivotPoint(Vector2f(50, 50));

    auto text = std::make_shared<Text>();
    sf::Font* font = this->resource_manager->GetElement<FontResource>("font")->Font();

    text->setFont(*font);

    String string_value = to_string(value);
    text->setString(string_value);
    text->setCharacterSize(32);

    int text_length = 18 * string_value.getSize();
    int text_left_offset = (100 - text_length)/2;
    int text_top_offset = (100 - 46)/2;

    auto silhouette = std::make_shared<RectangularSilhouette>(this, 100, 100);
    AddSilhouette(silhouette);

    text->setPosition(text_left_offset, text_top_offset);

    AddShape(text);
}

void Cell::OnMouseOn() {
	BrushInRed();
}

void Cell::OnMouseOff() {
	BrushInCellColor();
}

void Cell::BrushInRed(){
	Depth(100);
	tile->setFillColor(Color(200, 30, 30));
	animation_controller->SetParamValue("State", "1");
}

void Cell::BrushInCellColor() {
	Depth(0);
	tile->setFillColor(GetColor(value));
	animation_controller->SetParamValue("State", "0");
}

Color Cell::GetColor(int value){
    switch (value){
        case 2:
            return Color(238, 228, 218);
        case 4:
            return Color(237, 224, 200);
        case 8:
            return Color(242, 177, 121);
        case 16:
            return Color(245, 149, 99);
        case 32:
            return Color(246, 124, 95);
        case 64:
            return Color(246, 94, 59);
        case 128:
            return Color(237, 207, 114);
        case 256:
            return Color(237, 204, 97);
        case 512:
            return Color(237, 200, 80);
        case 1024:
            return Color(237, 197, 63);
        case 2048:
            return Color(237, 194, 46);
        default:
            return Color(60, 58, 50);
    }
}