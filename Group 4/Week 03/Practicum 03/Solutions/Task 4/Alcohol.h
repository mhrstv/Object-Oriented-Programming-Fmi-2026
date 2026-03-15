#pragma once

class Alcohol
{
private:
    char name[128];
    double price;
    int quantity;

public:
    Alcohol();
    Alcohol(const char* _name, double _price, int _quantity = 1);

    double getPrice() const;
    const char* getName() const;
    int getQuantity() const;

    void addQuantity(int count);
    void removeQuantity();
};