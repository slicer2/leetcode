#include <iostream>
#include <climits>

using namespace std;

class Solution {
	public:
		int sqrt(int x) {
			if (x == 0 || x == 1)
				return x;

			int start = 1, end = x;

			while (start+1 < end) {
				int mid = (start+end)/2;

				if (x/mid >= mid)
					start = mid;
				else
					end = mid;
			}

			return start;
		}
};

int main() {
	int x;

	cout << "max int = " << INT_MAX<< endl;
	cin >> x;

	Solution sol;

	cout << sol.sqrt(x) << endl;

	return 0;
}
