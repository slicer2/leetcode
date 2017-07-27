//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	list<pair<int, int>> val;
	int capacity;

	public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())
			return -1;

		auto res = *mp[key];
		val.push_front(res);
		val.erase(mp[key]);
		mp[key] = val.begin();
		return res.second;
	}

	void set(int key, int value) {
		if (mp.find(key) == mp.end()) {
			val.push_front(make_pair(key, value));
			mp.insert(make_pair(key, val.begin()));
			if (val.size() > capacity) {
				mp.erase(val.back().first);
				val.pop_back();
			}
		}
		else {
			mp[key]->second = value;
			val.push_front(*mp[key]);
			val.erase(mp[key]);
			mp[key] = val.begin();
		}
	}
};


int main() {

	int op, key, val;

	int capacity;

	cin >> capacity;

	LRUCache lru(capacity);

	while(cin >> op >> key >> val) {
		if (op) {
			//cerr << "inserting (" << key << ", " << val << ")" << endl;
			cerr << "setting (" << key << ", "  << val << ")" << endl;
			lru.set(key, val);
		}
		else {
			//cerr << "getting (" << key << ", " << val << ")" << endl;
			cerr << "getting " << key << endl;
			cerr << "got " << lru.get(key) << endl;
		}
	}

	return 0;
}
