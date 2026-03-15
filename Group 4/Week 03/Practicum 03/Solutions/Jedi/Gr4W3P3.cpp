#include <iostream>
#include <string>

#include "Jedi.h"
#include "LightSaber.h"
#include "JediCollection.h"
#include "JediIO.h"

int main()
{
    JediCollection collection;

    LightSaber ls1(LightSaberColor::GREEN, LightSaberType::SINGLEBLADED);
    LightSaber ls2(LightSaberColor::BLUE, LightSaberType::DOUBLE_BLADED);

    collection.addJedi(Jedi(std::string("Luke Skywalker"), 25, 900, ls1));
    collection.addJedi(Jedi(std::string("Yoda"), 900, 1500, ls2));

    std::cout << "Original collection:\n";
    collection.print();

    const std::string txtFile = "jedis.txt";
    const std::string binFile = "jedis.bin";

    JediIO::saveToTxt(collection, txtFile);
    JediIO::saveToBinary(collection, binFile);

    std::cout << "\nLoaded from text:\n";
    JediCollection fromTxt = JediIO::readFromTxt(txtFile);
    fromTxt.print();

    std::cout << "\nLoaded from binary:\n";
    JediCollection fromBin = JediIO::readFromBinary(binFile);
    fromBin.print();

    return 0;
}