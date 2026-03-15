#include "Jedi.h"
#include <iostream>

Jedi::Jedi(const std::string& name, unsigned age, unsigned power, const LightSaber& lightSaber) : name(std::move(name)), age(age), power(power), ls(lightSaber)
{ }

Jedi::Jedi(const std::string& name, unsigned age, unsigned power, LightSaberType lightSaberType, LightSaberColor lightSaberColor) : name(std::move(name)), age(age), power(power), ls({lightSaberColor, lightSaberType})
{ }

Jedi::Jedi(const std::string& name, unsigned age, unsigned power, LightSaberColor lightSaberColor, LightSaberType lightSaberType) : name(std::move(name)), age(age), power(power), ls({lightSaberColor, lightSaberType})
{ }

Jedi::Jedi() : name(""), age(0), power(0), ls({ LightSaberColor::RED,LightSaberType::SINGLEBLADED }) {}

void Jedi::printJedi() const
{
	std::cout << "Name: " << this->name << "\nAge: " << this->age << "\nPower: " << this->power;
	this->ls.printSaber();
	std::cout << std::endl;
}

const std::string Jedi::getName() const
{
	return this->name;
}

unsigned Jedi::getAge() const
{
	return this->age;
}

unsigned Jedi::getPower() const
{
	return this->power;
}

LightSaber Jedi::getLs() const
{
	return this->ls;
}
