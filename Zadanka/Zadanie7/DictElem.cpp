#include <string>

template<typename Key, typename Val>
struct DictElem
{
public:
	DictElem(Key k, Val val) :key(k), value(val) {}
	Key key;
	Val value;
};