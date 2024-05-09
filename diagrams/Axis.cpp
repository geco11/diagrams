#include "Axis.h"
#include <sstream>
#include <iomanip>
sf::Text Axis::retText(double a)const
{
    std::ostringstream out;
    out<<std::setprecision(2) << a; // Set precision to 2
    std::string str = out.str();
    sf::Text text(str, font, 20u);
    text.setFillColor(col);
    return text;
}

void Axis::setXconfig(double a, double b, double c)
{
    ax = a;
    numcx = c;
    bx = b;
}

void Axis::setYconfig(double a, double b, double c)
{
    numcy = c;
    ay = a;
    by = b;
}

Axis::Axis(sf::Vector2f loc, sf::Vector2f size,sf::Color c)
{
	this->loc = loc;
	this->size = size;
    col = c;
    font.loadFromFile("EuropeanTypewriter.ttf");
}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    {// x-axis
        sf::RectangleShape line1(sf::Vector2f(size.x, 4));
        line1.setPosition(loc.x, loc.y + size.y);
        line1.setFillColor(col);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(150);
        line2.setFillColor(col);
        line2.setPosition(size.x + loc.x, loc.y + 4 + size.y);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(210);
        line3.setFillColor(col);
        line3.setPosition(size.x + loc.x, loc.y + 4 + size.y);
        target.draw(line3);
        double s = size.x*0.9 /(numcx-1);
        double step = (bx - ax) / (numcx-1);
        for (int i = 0; i < numcx; i++){
            sf::RectangleShape line4(sf::Vector2f(3, 12));
            line4.setFillColor(col);
            line4.setPosition(s*i+loc.x, loc.y-4+size.y);
            target.draw(line4);
            sf::Text text = retText(step*i+ax);
            text.setPosition(sf::Vector2f(s * i + loc.x-8, loc.y +14 + size.y));
            target.draw(text);
        }
    }

    {//y-axis
        sf::RectangleShape line1(sf::Vector2f(4, 4 + size.y));
        line1.setPosition(loc.x, loc.y);
        line1.setFillColor(col);
        target.draw(line1);
        sf::RectangleShape line2(sf::Vector2f(40, 4));
        line2.setRotation(60);
        line2.setFillColor(col);
        line2.setPosition(loc.x + 4, loc.y + 4);
        target.draw(line2);
        sf::RectangleShape line3(sf::Vector2f(40, 4));
        line3.setRotation(120);
        line3.setFillColor(col);
        line3.setPosition(loc.x + 3, loc.y + 4);
        target.draw(line3);
        double step = (by - ay) / (numcy-1);
        double s = size.y*0.9 / (numcy-1);
        for (int i = 0; i < numcy; i++) {
            sf::RectangleShape line5(sf::Vector2f(12, 3));
            line5.setFillColor(col);
            line5.setPosition( loc.x - 4,  (loc.y+size.y)-s * i);
            target.draw(line5);
            sf::Text text = retText(step * i + ay);
            text.setPosition(sf::Vector2f(loc.x-70, s*i+loc.y+50));
            target.draw(text);
        }
    }











   /* sf::Font font;
    font.loadFromFile("EuropeanTypewriter.ttf");
    sf::Text text("grdffgj", font, 20u);
    text.setFillColor(sf::Color(0, 0, 0));
    text.setPosition(sf::Vector2f(300,300));
    target.draw(text);*/
}