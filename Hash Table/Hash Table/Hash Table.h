#pragma once
#include <string>
#include <list>
#include <vector>

struct Set
{

	std::vector<std::list<std::string>> buckets;
};

void constructor(Set & s);
void add(Set & s, std::string const & str);
void deleteElement(Set & s, std::string const & str);
bool exists(Set const & s, std::string const & str);