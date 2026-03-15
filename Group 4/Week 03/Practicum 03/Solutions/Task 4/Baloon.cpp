#include "Baloon.h"
#include <string>

Baloon::Baloon() : price(0.0), quantity(0)
{
    strcpy(color, "white");
}

Baloon::Baloon(double _price, const char* _color, int _quantity) : price(_price), quantity(_quantity)
{
    setColor(_color);
}

double Baloon::getPrice() const
{
    return price;
}

const char* Baloon::getColor() const
{
    return color;
}

int Baloon::getQuantity() const
{
    return quantity;
}

void Baloon::setPrice(double _price)
{
    price = _price;
}

void Baloon::setColor(const char* _color)
{
    strcpy(color, _color);
    color[15] = '\0';
}

void Baloon::setQuantity(int _quantity)
{
    quantity = _quantity;
}

void Baloon::addQuantity(int count)
{
    quantity += count;
}

bool Baloon::removeQuantity(int count)
{
    if (quantity >= count)
    {
        quantity -= count;
        return true;
    }
    quantity = 0;
    return false;
}