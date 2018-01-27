// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainScene.h"

using namespace sf;
using namespace std;
using namespace gameengine;

int W = 1200;
int H = 800;

int main() {
	srand(time(0));

	RenderWindow app(VideoMode(W, H), "Match 2048");
	app.setFramerateLimit(60);

	MainScene scene(app);
	scene.Init();

	while (app.isOpen()) {
		Event event;
		while (app.pollEvent(event)) {
			if (event.type == Event::Closed)
				app.close();
		}
		app.clear();

		scene.Update();
		scene.Draw();

		app.display();
		sleep(sf::milliseconds(10));
	}

	return 0;
}

