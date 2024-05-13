#pragma once
#include <string>

template<typename Val>
struct DictElem
{
public:
	DictElem(std::string k, Val val);
	std::string key;
	Val value;
};

