//#include "Dictionary.hpp"
#include <stdexcept>

#include "DictElem.cpp"  // linker is problematic with hpp
#include <vector>
#include <string>

template <typename Key, typename Value>
class Dictionary
{
public:
	Dictionary() {};
	Value operator[](Key key);
	void append(Key key, Value value);
	void remove(Key key);
	bool key_exists(Key k);
private:
	std::vector<DictElem<Key, Value>> elems;
};



template <typename Key, typename Value>
Value Dictionary<Key, Value>::operator[](Key key)
{
	for (DictElem elem : elems)
	{
		if (elem.key == key) return elem.value;
	}
	throw std::domain_error("No element with this name!");
}


template <typename Key, typename Value>
void Dictionary<Key, Value>::append(Key key, Value value)
{
	if (!key_exists(key)) elems.push_back(DictElem<Key, Value>(key, value));
	else throw std::domain_error("This name already exists!");
}

template <typename Key, typename Value>
void Dictionary<Key, Value>::remove(Key key)
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

template <typename Key, typename Value>
bool Dictionary<Key, Value>::key_exists(Key k)
{
	for (DictElem elem : elems)
	{
		if (elem.key == k) return true;
	}
	return false;
}

