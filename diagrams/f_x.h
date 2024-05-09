#pragma once
#include"DrawableInNewWindow.h"
#include<SFML/Graphics.hpp>
#include<functional>
#include"Axis.h"
class f_x :public DrawableInNewWindow{
	double a, b;
	std::function<double(double)> calc;
	sf::Vector2f loc,size;
public:
	f_x(double n, double m,std::function<double(double)> func);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void setLoc(double x, double y);
	void setSize(double x, double y);
private:
	bool numCheck(double a)const;
	void countSetings(int x, int y)override;
};

