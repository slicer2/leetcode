#include <iostream>

using namespace std;

class Solution {

	int nFact(int n, int c) {
		int fact = c;
		int cnt = 0;

		while (fact <= n) {
			cnt += n / fact;
			fact *= c;
		}

		return cnt;
	}

	public:
		int trailingZeroes(int n) {
			return nFact(n, 5);
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.trailingZeroes(n) << endl;

	return 0;
}
