#include <iostream>
#include <vector>
#include "dan.h"
#include <unordered_map>

using namespace std;

class Solution {
	public:
		int majorityElement(vector<int> &num) {
			unordered_map<int, int> freq;
			int th = num.size() / 2;

			for (auto &x: num) {
				freq[x]++;
				if (freq[x] > th)
					return x;
			}

			return 0;
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;
	cout << sol.majorityElement(num) << endl;

	return 0;
}
