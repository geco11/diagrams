#include"DrawableInNewWindow.h"

void DrawableInNewWindow::drawInNewWindow(int x, int y, bool sets) {
	if (sets) {
		countSetings(x, y);
	}
	sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(225, 225, 225));
		window.draw(*this);
		window.display();
	}
}
