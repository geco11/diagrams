#include<algorithm>
#include "BarChart.h"
#include"DownloadFromFile.h"
#include<cmath>
void BarChart::setSize(float x, float y)
{
	size.x = x;
	size.y = y;
}
void BarChart::setBarsColor(int r, int g, int b, int a) {
	barsColor.r = r;
	barsColor.g = g;
	barsColor.b = b;
	barsColor.a = a;
}
BarChart::BarChart(const std::vector<double>* arr){
	makeBars(arr);
	barsColor = sf::Color::Blue;
}
BarChart::BarChart(const char* path) {
	std::vector<double> a=vectorFromFile(path);
	std::sort(a.begin(),a.end());
	makeBars(&a);
	barsColor = sf::Color::Blue;
}
void BarChart::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	double k = (size.y * 0.9) / maxBar();
	float width = (size.x * 0.9) / bars.size();
	for (int i = 0; i < bars.size(); ++i) {
		sf::RectangleShape bar(sf::Vector2f(width, bars[i].second * k));
		bar.setFillColor(barsColor);
		bar.setOutlineColor(sf::Color(255 - barsColor.r, 255 - barsColor.g, 255 - barsColor.b, barsColor.a));
		bar.setOutlineThickness(2);
		int x = bar.getSize().x;
		int y = bar.getSize().y;
		bar.setPosition((bar.getOutlineThickness()+x) * i + loc.x, loc.y + size.y - y);
		target.draw(bar);
	}
	{// x-axis
		sf::RectangleShape line1(sf::Vector2f(size.x, 4));
		line1.setPosition(loc.x, loc.y + size.y);
		line1.setFillColor(sf::Color::Black);
		target.draw(line1);
		sf::RectangleShape line2(sf::Vector2f(40, 4));
		line2.setRotation(150);
		line2.setFillColor(sf::Color::Black);
		line2.setPosition(size.x + loc.x, loc.y + 4 + size.y);
		target.draw(line2);
		sf::RectangleShape line3(sf::Vector2f(40, 4));
		line3.setRotation(210);
		line3.setFillColor(sf::Color::Black);
		line3.setPosition(size.x + loc.x, loc.y + 4 + size.y);
		target.draw(line3);
    }

	{//y-axis
		sf::RectangleShape line1(sf::Vector2f(4, size.y+4));
		line1.setPosition(loc);
		line1.setFillColor(sf::Color::Black);
		target.draw(line1);
		sf::RectangleShape line2(sf::Vector2f(40, 4));
		line2.setRotation(60);
		line2.setFillColor(sf::Color::Black);
		line2.setPosition( loc.x+4, loc.y +4);
		target.draw(line2);
		sf::RectangleShape line3(sf::Vector2f(40, 4));
		line3.setRotation(120);
		line3.setFillColor(sf::Color::Black);
		line3.setPosition( loc.x+3, loc.y + 4);
		target.draw(line3);
    }
	
}

int BarChart::mRet(int n)
{
	return 1+3.3221*log(n);
}
void BarChart::countSetings(int x, int y) {
	size.x = x * 0.8;
	size.y = y * 0.8;
	loc.y = y *0.1;
	loc.x = x * 0.1;
}

double BarChart::fStep(double min,double max,int n){
	double range = max - min;
	return range / mRet(n);
}

void BarChart::makeBars(const std::vector<double>* arr){
	int curr = 0;
	double step = fStep((*arr)[0],(*arr)[arr->size()-1],(arr->size()));
	for (int i = 0; i < mRet(arr->size()); ++i) {
		double l = (*arr)[0] + step * i;
		double r = l + step;
		int t = 0;
		for (; r > (*arr)[curr];++curr)++t;
		std::pair <double, int> a={l+step/2,t};
		bars.push_back(a);
	}
}

int BarChart::maxBar()const
{
	int max = 0;
	for (auto el : bars) {
		if (el.second > max)max = el.second;
	}
	return max;
}


