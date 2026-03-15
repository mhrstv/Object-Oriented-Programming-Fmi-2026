#pragma once
#include "JediCollection.h"
class JediData
{
public:
	static void sortByAge(JediCollection&);
	static void sortByPower(JediCollection&);
	static LightSaberColor mostPopularSaberColor(const JediCollection&);
	static LightSaberType mostPopularSaberType(const JediCollection&);
};