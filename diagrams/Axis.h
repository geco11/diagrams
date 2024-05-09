#pragma once
#include<SFML/Graphics.hpp>
#include"LineWithWidth.h"
class Axis : public sf::Drawable
{
	sf::Font font;
	sf::Vector2f loc, size;
	sf::Color col;
	double ax, bx,ay,by,numcx,numcy;
	sf::Text retText(double a)const;
public:
	void setXconfig(double a,double b,double c);
	void setYconfig(double a, double b,double c);
	Axis(sf::Vector2f loc,sf::Vector2f size,sf::Color c);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

