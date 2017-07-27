#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {

	public:
		int divide(int dividend, int divisor) {
			if (divisor == 0) return INT_MAX;

			int sign = ((dividend > 0) ^ (divisor > 0))?-1:1;
			long dd = labs(dividend), ds = labs(divisor), q = 0;

			while (ds <= dd) {
				long multiple = 1, trial = ds;
				while ((trial << 1) <= dd){
					trial <<= 1;
					multiple <<= 1;
				}

				dd -= trial;
				q += multiple;
			}

			q = (sign>0)?q:-q;

			return (q+INT_MIN)?q:INT_MAX;
		}
};

int main() {
	int dividend, divisor;
	cin >> dividend >> divisor;

	//cout << INT_MAX << "   " << INT_MIN << endl;
	//cout << "-5/-2 = " << (-5)/(-2) << endl;
	//cout << "-5 /2 = " << (-5) / 2 << endl;
	//cout << "5/-2 = " << 5/(-2) << endl;
	//cout << "-1>>1 = " << ((-1)>>1) << endl;
	//cout << "5>>1 = " << (5 >> 1) << endl;

	Solution sol;

	cout << sol.divide(dividend, divisor) << endl;

	return 0;
}
