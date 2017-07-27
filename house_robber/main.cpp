#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int rob(vector<int> &num) {
			if (num.empty())
				return 0;

			int f_2 = 0, f_1 = 0;
			for (unsigned i=0; i<num.size(); i++)
			{
				int f = max(num[i]+f_2, f_1);
				f_2 = f_1;
				f_1 = f;
			}

			return f_1;
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;
	cout << sol.rob(num) << endl;
	return 0;
}
