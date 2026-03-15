#include "Alcohol.h"
#include <string>

Alcohol::Alcohol() : price(0.0), quantity(0)
{
    strcpy(name, "");
}

Alcohol::Alcohol(const char* _name, double _price, int _quantity) : price(_price), quantity(_quantity)
{
    strcpy(name, _name);
    name[127] = '\0';
}

double Alcohol::getPrice() const
{
    return price;
}

const char* Alcohol::getName() const
{
    return name;
}

int Alcohol::getQuantity() const
{
    return quantity;
}

void Alcohol::addQuantity(int count)
{
    quantity += count;
}

void Alcohol::removeQuantity()
{
    if (quantity > 0)
    {
        quantity--;
    }
}