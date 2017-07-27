#include <iostream>
#include <climits>

using namespace std;

class Solution {
	public:
		int reverse(int x) {
			int y = 0;
			while (x) {
				y = 10*y + (x % 10);
				x /= 10;
			}

			return y;
		}
};

int main() {
	int x;

	cin >> x;

	Solution sol;

	cout << sol.reverse(x) << endl;

	return 0;
}
