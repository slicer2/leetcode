#include <iostream>
using namespace std;

class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			uint32_t revInt;

			for (int i=0; i<32; i++) {
				uint32_t next_bit = n % 2;
				revInt = 2*revInt + next_bit;
				n /= 2;
			}

			return revInt;
		}
};

int main() {
	uint32_t n;
	cin >> n;
	
	Solution sol;
	cout << sol.reverseBits(n) << endl;

	return 0;
}
