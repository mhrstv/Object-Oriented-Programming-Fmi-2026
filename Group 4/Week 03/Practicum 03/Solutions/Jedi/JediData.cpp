#include "JediData.h"

void JediData::sortByAge(JediCollection& collection)
{
	Jedi* jedis = collection.getJedis();
	for (size_t i = 0; i < collection.getCount() - 1; i++)
	{
		for (size_t j = 0; j < collection.getCount() - i - 1; j++)
		{
			if (jedis[j].getAge() > jedis[j + 1].getAge())
			{
				Jedi temp = jedis[j];
				jedis[j] = jedis[j + 1];
				jedis[j + 1] = temp;
			}
		}
	}
	collection.setJedis(jedis);
	delete[] jedis;
}

void JediData::sortByPower(JediCollection& collection)
{
	Jedi* jedis = collection.getJedis();
	for (size_t i = 0; i < collection.getCount() - 1; i++)
	{
		for (size_t j = 0; j < collection.getCount() - i - 1; j++)
		{
			if (jedis[j].getPower() > jedis[j + 1].getPower())
			{
				Jedi temp = jedis[j];
				jedis[j] = jedis[j + 1];
				jedis[j + 1] = temp;
			}
		}
	}
	collection.setJedis(jedis);
	delete[] jedis;
}

LightSaberColor JediData::mostPopularSaberColor(const JediCollection& collection)
{
	LightSaberColor currentColor = (LightSaberColor)0;
	LightSaberColor mostPopularColor = LightSaberColor::UNSIGNED;
	int currentCnt = 0;
	int maxCnt = 0;
	Jedi* jedis = collection.getJedis();
	for (size_t i = 0; i < (size_t)LightSaberColor::UNSIGNED; i++)
	{
		currentColor = (LightSaberColor)(i);
		for (size_t j = 0; j < collection.getCount(); j++)
		{
			if (jedis[i].getLs().color == currentColor)
			{
				currentCnt++;
			}
			if (currentCnt > maxCnt)
			{
				mostPopularColor = currentColor;
				maxCnt = currentCnt;
			}
		}
	}
	delete[] jedis;
	return mostPopularColor;
}

LightSaberType JediData::mostPopularSaberType(const JediCollection& collection)
{
	LightSaberType currentType = (LightSaberType)0;
	LightSaberType mostPopularType = LightSaberType::UNSIGNED;
	int currentCnt = 0;
	int maxCnt = 0;
	Jedi* jedis = collection.getJedis();
	for (size_t i = 0; i < (size_t)LightSaberType::UNSIGNED; i++)
	{
		currentType = (LightSaberType)(i);
		for (size_t j = 0; j < collection.getCount(); j++)
		{
			if (jedis[i].getLs().type == currentType)
			{
				currentCnt++;
			}
			if (currentCnt > maxCnt)
			{
				mostPopularType = currentType;
				maxCnt = currentCnt;
			}
		}
	}
	delete[] jedis;
	return mostPopularType;
}
