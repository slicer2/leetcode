#include <iostream>

using namespace std;

class Solution {
	public:
		int climbStairs(int n) {
			if (n == 0)
				return 1;
			
			if (n==1)
				return 1;

			int curr;
			int prev = 1, pprev = 1;

			for (int k=2; k<=n; k++) {
				curr = prev + pprev;
				pprev = prev;
				prev = curr;
			}

			return curr;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;

	cout << sol.climbStairs(n) << endl;

	return 0;
}
