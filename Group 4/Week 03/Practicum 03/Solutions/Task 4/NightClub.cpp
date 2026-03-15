#include "NightClub.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

NightClub::NightClub() : balloonsCount(0), totalBalloonsStored(0), nargasCount(0), totalNargasStored(0), alcoholsCount(0), totalAlcoholsStored(0)
{
}

void NightClub::addBaloonFromFile(const char* filename)
{
    std::ifstream in(filename);
    if (!in)
    {
        return;
    }

    char color[16];
    double price;
    if (in.getline(color, 16, '-'))
    {
        in >> price;
        for (int i = 0; i < balloonsCount; i++)
        {
            if (strcmp(balloons[i].getColor(), color) == 0 && balloons[i].getPrice() == price)
            {
                if (totalBalloonsStored < 1024)
                {
                    balloons[i].addQuantity(1);
                    totalBalloonsStored++;
                }
                in.close();
                return;
            }
        }
        if (totalBalloonsStored < 1024 && balloonsCount < 1024)
        {
            balloons[balloonsCount++] = Baloon(price, color, 1);
            totalBalloonsStored++;
        }
    }
    in.close();
}

void NightClub::addNargaFromFile(const char* filename)
{
    std::ifstream in(filename);
    if (!in)
    {
        return;
    }

    char brand[1024];
    char flavor[64];
    double price;
    if (in.getline(brand, 1024, '-'))
    {
        if (in.getline(flavor, 64, '-'))
        {
            in >> price;
            for (int i = 0; i < nargasCount; i++)
            {
                if (strcmp(nargas[i].getBrand(), brand) == 0 && strcmp(nargas[i].getFlavor(), flavor) == 0)
                {
                    if (totalNargasStored < 256)
                    {
                        nargas[i].addQuantity(1);
                        totalNargasStored++;
                    }
                    in.close();
                    return;
                }
            }
            if (totalNargasStored < 256 && nargasCount < 256)
            {
                nargas[nargasCount++] = Narga(price, brand, flavor, 1);
                totalNargasStored++;
            }
        }
    }
    in.close();
}

void NightClub::addAlcoholFromFile(const char* filename)
{
    std::ifstream in(filename);
    if (!in)
    {
        return;
    }

    char name[128];
    double price;
    if (in.getline(name, 128, '-'))
    {
        in >> price;
        for (int i = 0; i < alcoholsCount; i++)
        {
            if (strcmp(alcohols[i].getName(), name) == 0)
            {
                if (totalAlcoholsStored < 512)
                {
                    alcohols[i].addQuantity(1);
                    totalAlcoholsStored++;
                }
                in.close();
                return;
            }
        }
        if (totalAlcoholsStored < 512 && alcoholsCount < 512)
        {
            alcohols[alcoholsCount++] = Alcohol(name, price, 1);
            totalAlcoholsStored++;
        }
    }
    in.close();
}

void NightClub::removeBaloon(const char* color)
{
    for (int i = 0; i < balloonsCount; i++)
    {
        if (strcmp(balloons[i].getColor(), color) == 0 && balloons[i].getQuantity() > 0)
        {
            balloons[i].removeQuantity(1);
            totalBalloonsStored--;
            return;
        }
    }
}

void NightClub::removeNarga(const char* brand, const char* flavor)
{
    for (int i = 0; i < nargasCount; i++)
    {
        if (strcmp(nargas[i].getBrand(), brand) == 0 && strcmp(nargas[i].getFlavor(), flavor) == 0 && nargas[i].getQuantity() > 0)
        {
            nargas[i].removeQuantity();
            totalNargasStored--;
            return;
        }
    }
}

void NightClub::removeAlcohol(const char* name)
{
    for (int i = 0; i < alcoholsCount; i++)
    {
        if (strcmp(alcohols[i].getName(), name) == 0 && alcohols[i].getQuantity() > 0)
        {
            alcohols[i].removeQuantity();
            totalAlcoholsStored--;
            return;
        }
    }
}

bool NightClub::hasBaloonColor(const char* color) const
{
    for (int i = 0; i < balloonsCount; i++)
    {
        if (strcmp(balloons[i].getColor(), color) == 0 && balloons[i].getQuantity() > 0)
        {
            return true;
        }
    }
    return false;
}

bool NightClub::hasAlcoholName(const char* name) const
{
    for (int i = 0; i < alcoholsCount; i++)
    {
        if (strcmp(alcohols[i].getName(), name) == 0 && alcohols[i].getQuantity() > 0)
        {
            return true;
        }
    }
    return false;
}

bool NightClub::hasNargaFlavor(const char* flavor) const
{
    for (int i = 0; i < nargasCount; i++)
    {
        if (strcmp(nargas[i].getFlavor(), flavor) == 0 && nargas[i].getQuantity() > 0)
        {
            return true;
        }
    }
    return false;
}

double NightClub::calculateClientBill(const char* filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        return 0.0;
    }

    double totalSum = 0.0;
    char line[2048];
    int currentSection = 0;

    while (in.getline(line, 2048))
    {
        if (strcmp(line, "Alchohols:") == 0 || strcmp(line, "Alcohols:") == 0)
        {
            currentSection = 1;
            continue;
        }
        if (strcmp(line, "Baloons:") == 0 || strcmp(line, "Balloons:") == 0)
        {
            currentSection = 2;
            continue;
        }
        if (strcmp(line, "Nargas:") == 0 || strcmp(line, "Narga:") == 0)
        {
            currentSection = 3;
            continue;
        }

        if (strlen(line) == 0)
        {
            continue;
        }

        std::istringstream iss(line);

        if (currentSection == 1)
        {
            char name[128];
            int count;
            if (iss.getline(name, 128, '-'))
            {
                if (iss >> count)
                {
                    for (int i = 0; i < alcoholsCount; i++)
                    {
                        if (strcmp(alcohols[i].getName(), name) == 0)
                        {
                            totalSum += alcohols[i].getPrice() * count;
                            break;
                        }
                    }
                }
            }
        }
        else if (currentSection == 2)
        {
            char color[16];
            int count;
            if (iss.getline(color, 16, '-'))
            {
                if (iss >> count)
                {
                    for (int i = 0; i < balloonsCount; i++)
                    {
                        if (strcmp(balloons[i].getColor(), color) == 0)
                        {
                            totalSum += balloons[i].getPrice() * count;
                            break;
                        }
                    }
                }
            }
        }
        else if (currentSection == 3)
        {
            char brand[1024];
            char flavor[64];
            int count;
            if (iss.getline(brand, 1024, '-'))
            {
                if (iss.getline(flavor, 64, '-'))
                {
                    if (iss >> count)
                    {
                        for (int i = 0; i < nargasCount; i++)
                        {
                            if (strcmp(nargas[i].getBrand(), brand) == 0 && strcmp(nargas[i].getFlavor(), flavor) == 0)
                            {
                                totalSum += nargas[i].getPrice() * count;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    in.close();
    return totalSum;
}

void NightClub::calculateDailyProfit(Client* clients, int numClients)
{
    std::ofstream out("money.bin", std::ios::binary);
    if (!out)
    {
        return;
    }

    for (int i = 0; i < numClients; i++)
    {
        double amountOwed = calculateClientBill(clients[i].billFilename);
        int nameLen = strlen(clients[i].name);

        out.write((const char*)&nameLen, (const char*)(&nameLen + 1) - (const char*)&nameLen);
        out.write(clients[i].name, nameLen);
        out.write((const char*)&amountOwed, (const char*)(&amountOwed + 1) - (const char*)&amountOwed);
    }
    out.close();
}