#include "LightSaber.h"
#include <iostream>

const char* saberColorToString(LightSaberColor saberColor)
{
	switch (saberColor)
	{
	case LightSaberColor::RED:
		return "Red";
		break;
	case LightSaberColor::YELLOW:
		return "Yellow";
		break;
	case LightSaberColor::PURPLE:
		return "Purple";
		break;
	case LightSaberColor::BLUE:
		return "Blue";
		break;
	case LightSaberColor::GREEN:
		return "Green";
		break;
	}
    return "Unspecified";
}

const char* saberTypeToString(LightSaberType saberType)
{
	switch (saberType)
	{
	case LightSaberType::SINGLEBLADED:
		return "Singlebladed";
		break;
	case LightSaberType::DOUBLE_BLADED:
		return "Double Bladed";
		break;
	case LightSaberType::CROSSGUARD:
		return "Crossguard";
		break;
	}
    return "Unspecified";
}


void LightSaber::printSaber() const
{
    std::cout << "\nLight Saber: " << saberColorToString(this->color) << " " << saberTypeToString(this->type);
}
