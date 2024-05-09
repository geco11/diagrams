#pragma once
#include<SFML/Graphics.hpp>
class DrawableInNewWindow :public sf::Drawable {
public:
	void drawInNewWindow(int x, int y, bool sets = true);
	virtual void countSetings(int x,int y) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
};