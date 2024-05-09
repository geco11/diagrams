#include "x_axis.h"


void x_axis::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	sf::RectangleShape line1(sf::Vector2f(length,4));
	line1.setPosition(loc);
	line1.setFillColor(sf::Color(0, 0, 0));
	target.draw(line1);
	sf::RectangleShape line2(sf::Vector2f(40,4));
	line2.setRotation(150);
	line2.setFillColor(sf::Color::Black);
	line2.setPosition(length + loc.x, loc.y+4);
	target.draw(line2);
	sf::RectangleShape line3(sf::Vector2f(40, 4));
	line3.setRotation(210);
	line3.setFillColor(sf::Color::Black);
	line3.setPosition(length + loc.x, loc.y + 4);
	target.draw(line3);
	double start = loc.x + 0.025 * length;
	double finish =start + length * 0.95;
	double k = (0.95 * length) / (fMax()-fMin());
	for (int i = 0; i < (*data).size(); ++i) {
		sf::CircleShape c(4);
		c.setFillColor(sf::Color::Red);
		c.setPosition(((( * data)[i] - fMin()) * k)+start, loc.y);
		target.draw(c);
	}
}
void x_axis::setLegnth(int a) {
	length = a;
}
void x_axis::setLoc(float x, float y) {
	loc.x = x;
	loc.y = y;
}
void x_axis::countSetings(int x, int y){
	length = x * 0.8;
	loc.y = y / 2;
	loc.x = x*0.1;
}
double x_axis::fMin()const {
	const std::vector<double>& arr = *data;
	double min = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (min > arr[i])min = arr[i];
	}
	return min;
}
double x_axis::fMax()const {
	const std::vector<double>& arr = *data;
	double max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (max < arr[i])max = arr[i];
	}
	return max;
}
