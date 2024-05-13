#include <string>

template<typename Val>
struct DictElem
{
public:
	DictElem(std::string k, Val val) :key(k), value(val) {}
	std::string key;
	Val value;
};