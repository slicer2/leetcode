#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string convertToTitle(int n) {
			string ret;

			while (n > 0) {
				switch (n % 26) {
					case 0:
						ret += 'Z';
						n = n / 26 -1;
						break;
					default:
						ret += (n%26-1)+'A';
						n = n / 26;
				}
			}

			unsigned p = 0, q = ret.length()-1;
			for (; p<q; p++, q--) {
				char t = ret[p];
				ret[p] = ret[q];
				ret[q] = t;
			}

			return ret;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;

	cout << sol.convertToTitle(n) << endl;

	return 0;
}
