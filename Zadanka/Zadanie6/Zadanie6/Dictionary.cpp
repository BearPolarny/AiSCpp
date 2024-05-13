//#include "Dictionary.hpp"
#include <stdexcept>

#include "DictElem.cpp"
#include <vector>
#include <string>

template <typename Value>
class Dictionary
{
public:
	Dictionary() {};
	Value operator[](std::string key);
	void append(std::string key, Value value);
	void remove(std::string key);
	bool key_exists(std::string k);
private:
	std::vector<DictElem<Value>> elems;
};



template<typename Value>
Value Dictionary<Value>::operator[](std::string key)
{
	for (DictElem elem : elems)
	{
		if (elem.key == key) return elem.value;
	}
	throw std::domain_error("No element with this name!");
}

template<typename Value>
void Dictionary<Value>::append(std::string key, Value value)
{
	if (!key_exists(key)) elems.push_back(DictElem<Value>(key, value));
	else throw std::domain_error("This name already exists!");
}

template<typename Value>
void Dictionary<Value>::remove(std::string key)
{
	int pos = 0;
	if (key_exists(key))
	{
		for (int i = 0; i < elems.size(); i++)
		{
			if (elems[i].key = key) {
				pos = i;
				break;
			}
		}
		elems.erase(pos);
	} else throw std::domain_error("No element with this name!");
	return;
}

template<typename Value>
bool Dictionary<Value>::key_exists(std::string k)
{
	for (DictElem elem : elems)
	{
		if (elem.key == k) return true;
	}
	return false;
}

