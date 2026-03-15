#pragma once

class Baloon
{
private:
    double price;
    char color[16];
    int quantity;

public:
    Baloon();
    Baloon(double _price, const char* _color, int _quantity = 1);

    double getPrice() const;
    const char* getColor() const;
    int getQuantity() const;

    void setPrice(double _price);
    void setColor(const char* _color);
    void setQuantity(int _quantity);

    void addQuantity(int count);
    bool removeQuantity(int count);
};