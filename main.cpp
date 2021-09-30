#include <iostream>
#include <utility>
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include "Headers/SceneObjects/Object.h"
#include "Headers/ContactListener.h"
#include "Headers/scales.h"
#include "Headers/b2Functions.h"
#include "Headers/SFMLFunctions.h"
#include "Headers/Scene.h"
#include "Headers/Game.h"

#include "Scenes/Scene1.h"
using namespace sf;

int main()
{
	Game game;
	b2World world(b2Vec2(0.f, 30.f));
	RenderWindow window(VideoMode(1900, 1000), "SFML works!");
	window.setFramerateLimit(70);
	Clock clock;

	std::unique_ptr<Scene> scene1 = std::make_unique<Scene1>(world, window);
	game.addScene(std::move(scene1));

	game.setActiveScene(0);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}

		world.Step(1 / 60.f, 8, 3);
		window.clear(Color(107, 140, 255));

		game.update(world, window);

		window.display();
	}
	return 0;
}