#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include "dan.h"


using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
            unordered_map<int, pair<int, int>> mp;
			int len = 0;
            for (auto x: num) {
                if (mp.find(x) == mp.end()) {
                    int left, right;
                    if (mp.find(x-1) != mp.end()) left = mp[x-1].first;
                    else left = x;
                    if (mp.find(x+1) != mp.end()) right = mp[x+1].second;
                    else right = x;
                    mp.insert(make_pair(x, make_pair(left, right)));
                    mp[left].second = right;
                    mp[right].first = left;
                    len = max(len, right-left+1);
                }
            }

            return len;
		}
};

int main() {
	int n;
	vector<int> num;

	while (cin >> n)
		num.push_back(n);

	cout << num << endl;

	Solution s;

	cout << s.longestConsecutive(num) << endl;
	return 0;
}
