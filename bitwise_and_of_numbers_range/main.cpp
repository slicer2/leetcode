#include <iostream>

using namespace std;

class Solution {
	public:
		int rangeBitwiseAnd(int m, int n) {
			if (m > n)
				return 0;

			int result = 0;
			int bitExtractor = ((int) 1 << 30);
			int bitPos = 30;

			while( (m & bitExtractor) == (n & bitExtractor) && bitPos >= 0){
				result |= (m & bitExtractor);
				bitPos--;
				bitExtractor >>= 1;
			}

			return result;
		}
};


int main() {
	int m, n;

	cin >> m >> n;

	Solution sol;
	cout << sol.rangeBitwiseAnd(m, n) << endl;

	return 0;
}
