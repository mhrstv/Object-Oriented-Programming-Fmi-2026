#include "JediIO.h"
#include "Jedi.h"
#include "LightSaber.h"

#include <fstream>
#include <iostream>
#include <string>

void JediIO::saveToTxt(const JediCollection& collection, const std::string& fileName)
{
    std::ofstream saveFile(fileName);
    if (!saveFile) {
        std::cerr << "Error saving file!" << std::endl;
        return;
    }
    size_t count = collection.getCount();
    Jedi* jedis = collection.getJedis();
    for (size_t i = 0; i < count; ++i)
    {
        const Jedi& jedi = jedis[i];
        saveFile << jedi.getName() << ' ' << jedi.getAge() << ' ' << jedi.getPower() << ' ' << (int)jedi.getLs().color << ' ' << (int)jedi.getLs().type << '\n';
    }
}

void JediIO::saveToBinary(const JediCollection& collection, const std::string& fileName)
{
    std::ofstream saveFile(fileName, std::ios::binary);
    if (!saveFile) {
        std::cerr << "Error saving file!" << std::endl;
        return;
    }
    Jedi* jedis = collection.getJedis();
    size_t count = (size_t)collection.getCount();
    saveFile.write((char*)&count, sizeof(count));
    for (size_t i = 0; i < count; ++i)
    {
        const Jedi& jedi = jedis[i];
        char nameBuf[50] = {0};
        std::string name = jedi.getName();
        name.copy(nameBuf, 50);
        saveFile.write(nameBuf, sizeof(nameBuf));
        unsigned age = jedi.getAge();
        unsigned power = jedi.getPower();
        saveFile.write((char*)&age, sizeof(age));
        saveFile.write((char*)&power, sizeof(power));
        int color = (int)jedi.getLs().color;
        int type = (int)jedi.getLs().type;
        saveFile.write((char*)&color, sizeof(color));
        saveFile.write((char*)&type, sizeof(type));
    }
}

JediCollection JediIO::readFromTxt(const std::string& fileName)
{
    JediCollection collection;
    std::ifstream loadFile(fileName);
    if (!loadFile) {
        std::cerr << "Error reading from file!" << std::endl;
        return collection;
    }
    while (true)
    {
        std::string name;
        unsigned age;
        unsigned power;
        int colorInt, typeInt;
        loadFile >> name >> age >> power >> colorInt >> typeInt;
        if (loadFile.fail()) break;
        LightSaber ls((LightSaberColor)colorInt, (LightSaberType)typeInt);
        Jedi jedi(name, age, power, ls);
        collection.addJedi(jedi);
    }
    loadFile.close();
    std::cout << "Jedis were loaded from file " << fileName << std::endl;

    return collection;
}

JediCollection JediIO::readFromBinary(const std::string& fileName)
{
    JediCollection collection;
    std::ifstream loadFile(fileName, std::ios::binary);
    if (!loadFile) {
        std::cerr << "Error reading from file!" << std::endl;
        return collection;
    }

    size_t count = 0;
    loadFile.read((char*)&count, sizeof(count));
    for (size_t i = 0; i < count; ++i)
    {
        char nameBuf[50] = {0};
        loadFile.read(nameBuf, sizeof(nameBuf));
        std::string name = std::string(nameBuf);
        unsigned age = 0, power = 0;
        loadFile.read((char*)&age, sizeof(age));
        loadFile.read((char*)&power, sizeof(power));
        int colorInt = 0, typeInt = 0;
        loadFile.read((char*)&colorInt, sizeof(colorInt));
        loadFile.read((char*)&typeInt, sizeof(typeInt));
        LightSaber ls((LightSaberColor)colorInt, (LightSaberType)typeInt);
        Jedi jedi(name, age, power, ls);
        collection.addJedi(jedi);
    }

    loadFile.close();
    std::cout << "Jedis were loaded from file " << fileName << std::endl;

    return collection;
}