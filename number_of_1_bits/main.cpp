#include <iostream>
using namespace std;

class Solution {
	public:
		int hammingWeight(uint32_t n) {
			uint32_t weight = 0;

			while (n != 0) {
				uint32_t next_bit = n % 2;
				if (next_bit > 0)
					weight++;
				n /= 2;
			}

			return weight;
		}
};

int main() {
	uint32_t n;
	cin >> n;

	Solution sol;
	cout << sol.hammingWeight(n) << endl;

	return 0;
}
