#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
	public:
		double pow(double x, int n) {
			if (n == 0)
				return 1;

			bool neg = false;

			if (n < 0)
				neg = true;

			double result = 1;
			double mult = x;

			while (n != 0) {
				if (n % 2)
					if (neg)
						result /= mult;
					else
						result *= mult;

				n /= 2;
				mult *= mult;
			}

			return result;
		}
};

int main() {
	int n;
	double x;

	cin >> x >> n;

	cout << "INT_MAX = " << INT_MAX << endl;
	cout << "-1/2 = " << (-1)/2 << "   -1%1 = " << (-1)%2 << endl;
	cout << "-3/2 = " << (-3)/2 << "   -3%2 = " << (-3)%2 << endl;
	cout << "INT_MIN/2 = " << (INT_MIN)/2 << "   INT_MIN%2 = " << (INT_MIN)%2 << endl;

	Solution sol;

	cout << sol.pow(x, n) << endl;

	return 0;
}
