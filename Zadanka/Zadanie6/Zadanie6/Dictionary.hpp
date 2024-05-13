#pragma once
#include "DictElem.hpp"
#include <vector>
#include <string>

template <typename Value>
class Dictionary
{
public:
	Dictionary();
	Value operator[](std::string key);
	void append(std::string key, Value value);
	void remove(std::string key);
	bool key_exists(std::string k);
private:
	std::vector<DictElem<Value>> elems;
};

