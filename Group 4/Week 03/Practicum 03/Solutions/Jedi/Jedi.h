#pragma once
#include "LightSaber.h";
#include <string>
static const size_t MAX_NAME_LEN = 50;
class Jedi
{
private:
	std::string name;
	unsigned age;
	unsigned power;
	LightSaber ls;
public:
	Jedi(const std::string& name, unsigned, unsigned, const LightSaber&);
	Jedi(const std::string& name, unsigned, unsigned, LightSaberColor, LightSaberType);
	Jedi(const std::string& name, unsigned, unsigned, LightSaberType, LightSaberColor);
	Jedi();
public:
	void printJedi() const;
	const std::string getName() const;
	unsigned getAge() const;
	unsigned getPower() const;
	LightSaber getLs() const;
};