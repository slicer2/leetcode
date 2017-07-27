#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	struct MySort{
		bool operator ()(int x, int y) {
			string str_x = to_string(x);
			string str_y = to_string(y);

			if (str_x+str_y > str_y+str_x)
				return true;
			else
				return false;
		}
	}mysort;

	public:
		string largestNumber(vector<int> &num) {
			sort(num.begin(), num.end(), mysort);

			string s("");
			for (auto &x: num)
				s += to_string(x);

			if (s[0] == '0')
				return string("0");
			else
				return s;
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;
	cout << sol.largestNumber(num) << endl;

	return 0;
}
