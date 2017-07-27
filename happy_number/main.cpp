#include <unordered_set>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		bool isHappy(int n) {
			unordered_set<int> seen;
			seen.insert(n);

			while (true) {
				int next = 0;

				while (n > 0) {
					next += (n % 10)*(n % 10);
					n /= 10;
				}

				n = next;

				if (n == 1)
					return true;

				if (seen.find(n) != seen.end())
					return false;

				seen.insert(n);
			}
		}
};


int main() {
	int n;
	cin >> n;

	Solution sol;

	cout << sol.isHappy(n) << endl;
	return 0;
}
