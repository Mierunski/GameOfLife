// gameoflife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	using namespace std;
	cout << "Szerokosc planszy: ";
	int width;
	cin >> width;
	cout << "Wysokosc planszy: ";
	int height;
	cin >> height;
	cout << "Sterowanie:\nLPM - dodaj komorke\nPPM - usun komorke\nP - pauza/wznow\n";
	Engine engine(width, height);
	sf::RenderWindow window(sf::VideoMode(10 * width, 10 * height), "Game of Life");
	sf::RectangleShape shape(sf::Vector2f(10,10));
	shape.setFillColor(sf::Color::Green);
	sf::Clock zegar;
	bool pause = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				engine.SetCell(sf::Mouse::getPosition(window).x/10,sf::Mouse::getPosition(window).y/10 );
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				engine.ClearCell(sf::Mouse::getPosition(window).x / 10, sf::Mouse::getPosition(window).y / 10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {}
				engine.Step();
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {}
				pause = !pause;

			}
		}
		if (zegar.getElapsedTime().asMilliseconds() > 200 && !pause)
		{
			engine.Step();
			zegar.restart();
		}
		window.clear();
		bool ** map = engine.GetBoard();
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				if (map[i][j])
				{
					shape.setPosition(sf::Vector2f(10 * i, 10 * j));
					window.draw(shape);
				}
			}
		window.display();
	}

	return 0;
}
