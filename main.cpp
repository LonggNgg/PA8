/*
	Name: Long Nguyen
	Assignment: PA8
*/

#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int main()
{
	srand((unsigned)time(NULL));
	gameplay();


	









	/*int i = 0, j = 0;
	sf::RenderWindow window(sf::VideoMode(400, 800), "My Game");
	sf::RectangleShape ver_line[20];
	sf::RectangleShape hor_line[10];
	sf::CircleShape Board[20][10];

	for (i = 0; i < 20; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			Board[i][j].setRadius(20.f);
			Board[i][j].setFillColor(sf::Color::Blue);
			Board[i][j].setPosition((float)j * 40, (float)i * 40);
			hor_line[j].setSize(sf::Vector2f(3, 800));
			hor_line[j].setFillColor(sf::Color::White);
			hor_line[j].setPosition((float)j * 40, 0);
		}
		ver_line[i].setSize(sf::Vector2f(800, 3));
		ver_line[i].setFillColor(sf::Color::White);
		ver_line[i].setPosition(0, (float)i * 40);
	}

	ver_line[10].setFillColor(sf::Color::Red);

	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (i = 0; i < 20; ++i)
		{
			for (j = 0; j < 10; ++j)
			{
				window.draw(Board[i][j]);
				window.draw(hor_line[j]);
			}
			window.draw(ver_line[i]);
		}
		window.display();
	}*/
	return 0;
}