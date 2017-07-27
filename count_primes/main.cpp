#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class Solution {

	public:

		int countPrimes(int n) {
			if (n < 2)
				return 0;

			int nprime = 0;

			unsigned char *num = new unsigned char [n-2];
			memset(num, 0, n-2);

			int nextprime = 2;

			while (nextprime <= n-1) {
				nprime++;

				int mult = nextprime * 2;
				while (mult <= n-1) {
					if (num[mult-2] == 0)
						num[mult-2] = 1;

					mult += nextprime;
				}

				while (++nextprime <= n-1 && num[nextprime - 2] == 1);
			}

			return nprime;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.countPrimes(n) << endl;

	return 0;
}
