#include "Hash Table.h"
#include <algorithm>

int hashFunction(std::string const & str);

void constructor(Set & s)
{
	int size = 100;
	s.buckets.resize(size);
}

void add(Set & s, std::string const & str)
{
	if (!exists(s, str))
	{
		int hash = hashFunction(str) % s.buckets.size();
		s.buckets[hash].push_back(str);
	}
}

void deleteElement(Set & s, std::string const & str)
{
	if (exists(s, str))
	{
		int hash = hashFunction(str) % s.buckets.size();
		s.buckets[hash].remove(str);
	}
}

bool exists(Set const & s, std::string const & str)
{
	int hash = hashFunction(str) % s.buckets.size();
	return std::find(s.buckets[hash].begin(), s.buckets[hash].end(), str) !=
			s.buckets[hash].end();
}

int hashFunction(std::string const & str)
{
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		sum += sum * 5 + str[i];
	}
	return sum;
}