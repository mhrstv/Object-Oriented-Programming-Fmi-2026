#pragma once
enum class LightSaberColor
{
	RED, YELLOW, GREEN, PURPLE, BLUE,
	UNSIGNED
};

const char* saberColorToString(LightSaberColor);

enum class LightSaberType
{
	SINGLEBLADED, DOUBLE_BLADED, CROSSGUARD,
	UNSIGNED
};

const char* saberTypeToString(LightSaberType);

struct LightSaber
{
	LightSaberColor color;
	LightSaberType type;
	LightSaber(LightSaberColor color, LightSaberType type) : color(color), type(type) {};
	void printSaber() const;
};