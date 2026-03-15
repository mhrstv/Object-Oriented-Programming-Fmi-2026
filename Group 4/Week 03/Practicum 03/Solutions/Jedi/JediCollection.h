#pragma once
#include "Jedi.h"
class JediCollection
{
private:
	Jedi* jedis;
	size_t count{ 0 };
	size_t capacity = 100;
public:
	void addJedi(const Jedi& jedi);
	void removeJedi(const std::string& name);
	void print() const;
	size_t getCount() const;
	Jedi* getJedis() const;
	void setJedis(const Jedi* jedis);
public:
	JediCollection();
	~JediCollection();
};