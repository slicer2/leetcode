#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> result;
			result.push_back(0);

			for (int i=1; i<=n; i++) {
				int result_size = result.size();

				for (int j=0; j<result_size; j++) {
					int t = result[result_size-1-j] | (1 << (i-1));
					result.push_back(t);
				}
			}

			return result;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.grayCode(n) << endl;
	return 0;
}
