#pragma once
#include "JediCollection.h"
#include <string>

class JediIO
{
public:
    static void saveToTxt(const JediCollection& collection, const std::string& fileName);
    static void saveToBinary(const JediCollection& collection, const std::string& fileName);
    static JediCollection readFromTxt(const std::string& fileName);
    static JediCollection readFromBinary(const std::string& fileName);
};