#include <iostream>

using namespace std;

class Solution {
	public:
		bool isPalindrome(int x) {
			if (x == 0)
				return true;

			if (x < 0)
				return false;

			int y = 0;
			int z = x;
			while (x != 0) {
				y = y*10 + x % 10;
				x /= 10;
			}

			return (y == z);
		}
};

int main() {
	int x;
	cin >> x;

	Solution sol;

	cout << sol.isPalindrome(x) << endl;

	return 0;
}
