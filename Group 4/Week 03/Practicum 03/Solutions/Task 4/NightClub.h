#pragma once
#include "Baloon.h"
#include "Narga.h"
#include "Alcohol.h"
#include "Client.h"

class NightClub
{
private:
    Baloon balloons[1024];
    int balloonsCount;
    int totalBalloonsStored;

    Narga nargas[256];
    int nargasCount;
    int totalNargasStored;

    Alcohol alcohols[512];
    int alcoholsCount;
    int totalAlcoholsStored;

public:
    NightClub();

    void addBaloonFromFile(const char* filename);
    void addNargaFromFile(const char* filename);
    void addAlcoholFromFile(const char* filename);

    void removeBaloon(const char* color);
    void removeNarga(const char* brand, const char* flavor);
    void removeAlcohol(const char* name);

    bool hasBaloonColor(const char* color) const;
    bool hasAlcoholName(const char* name) const;
    bool hasNargaFlavor(const char* flavor) const;

    double calculateClientBill(const char* filename);
    void calculateDailyProfit(Client* clients, int numClients);
};