#pragma once
#include<utility>
#include<vector>
#include"DrawableInNewWindow.h"
#include<SFML/Graphics.hpp>
class BarChart :public DrawableInNewWindow{
	std::vector<std::pair<double, int>> bars;
	sf::Vector2f size;
	sf::Vector2f loc;
	sf::Color barsColor;
	double width;
public:
	void setSize(float x, float y);
	void setBarsColor(int r, int g, int b, int a = 255);
	BarChart(const std::vector<double>* arr);
	BarChart(const char* path);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	int mRet(int n);
	void countSetings(int x, int y)override;//false-custom setting
	double fStep(double min,double max,int n);
	void makeBars(const std::vector<double>* arr);
	int maxBar()const;
};

