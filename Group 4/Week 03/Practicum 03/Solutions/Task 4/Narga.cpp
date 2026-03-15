#include "Narga.h"
#include <iostream>
#include <string>

Narga::Narga() : price(0.0), quantity(0)
{
    strcpy(brand, "");
    strcpy(flavor, "");
}

Narga::Narga(double _price, const char* _brand, const char* _flavor, int _quantity) : price(_price), quantity(_quantity)
{
    strcpy(brand, _brand);
    brand[1023] = '\0';
    strcpy(flavor, _flavor);
    flavor[63] = '\0';
}

void Narga::readFromConsole()
{
    std::cin >> brand >> flavor >> price;
    quantity = 1;
}

void Narga::printToConsole() const
{
    std::cout << brand << " " << flavor << " " << price << " " << quantity << std::endl;
}

double Narga::getPrice() const
{
    return price;
}

const char* Narga::getBrand() const
{
    return brand;
}

const char* Narga::getFlavor() const
{
    return flavor;
}

int Narga::getQuantity() const
{
    return quantity;
}

void Narga::addQuantity(int count)
{
    quantity += count;
}

void Narga::removeQuantity()
{
    if (quantity > 0)
    {
        quantity--;
    }
}