#include "JediCollection.h"
#include <iostream>

void JediCollection::addJedi(const Jedi& jedi)
{
	if (this->count == this->capacity)
	{
		std::cerr << "Array capacity reached (100).";
		return;
	}
	this->jedis[count] = jedi;
	count++;
}

void JediCollection::removeJedi(const std::string& name)
{
	bool found = false;
	for (size_t i = 0; i < this->count; i++)
	{
		if (this->jedis[i].getName() == name)
		{
			for (size_t j = i; j < this->count - 1; j++)
			{
				this->jedis[j] = this->jedis[j + 1];
			}
			this->count--;
			return;
		}
	}
}

void JediCollection::print() const
{
	for (size_t i = 0; i < this->count; i++)
	{
		this->jedis[i].printJedi();
	}
}

size_t JediCollection::getCount() const
{
	return this->count;
}

Jedi* JediCollection::getJedis() const
{
	return this->jedis;
}

void JediCollection::setJedis(const Jedi* jedis)
{
	delete[] this->jedis;
	this->jedis = new Jedi[this->capacity];
	for (size_t i = 0; i < this->count; i++)
	{
		this->jedis[i] = jedis[i];
	}
}

JediCollection::JediCollection()
{
	jedis = new Jedi[this->capacity];
}

JediCollection::~JediCollection()
{
	delete[] jedis;
}
