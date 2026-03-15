#pragma once

class Narga
{
private:
    double price;
    char brand[1024];
    char flavor[64];
    int quantity;

public:
    Narga();
    Narga(double _price, const char* _brand, const char* _flavor, int _quantity = 1);

    void readFromConsole();
    void printToConsole() const;

    double getPrice() const;
    const char* getBrand() const;
    const char* getFlavor() const;
    int getQuantity() const;

    void addQuantity(int count);
    void removeQuantity();
};