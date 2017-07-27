#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int findPeakElement(const vector<int> &num) {
			for (unsigned i=0; i<num.size(); i++) {
				if (i == 0 || num[i-1] < num[i])
					if (i == num.size()-1 || num[i+1] < num[i])
						return i;
			}
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;

	cout << sol.findPeakElement(num) << endl;

	return 0;
}
