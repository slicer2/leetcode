#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {

	public:
		string longestPalindrome(string s) {
			string s0("#");
			for (auto x: s) s0 += string({x, '#'});

			int sz = s0.size(), c = 0, R = 0, maxc = 0, maxR = 0;
			vector<int>dist(sz, 0);

			for (int p=1; p<sz; p++) {
				if (c+R >= p)
					if (dist[2*c-p]+p < c+R)
						dist[p] = dist[2*c-p];
					else {
						R = c+R-p; c = p;
						while (p+R+1 < sz && p-R-1 >=0 && s0[p+R+1] == s0[p-R-1]) R++;
						dist[p] = R;
					}
				else {
					c = p; R = 0;
					while (p+R+1 < sz && p-R-1 >=0 && s0[p+R+1] == s0[p-R-1]) R++;
					dist[p] = R;
				}

				if (maxR < dist[p]) {
					maxR = dist[p];
					maxc = p;
				}
			}


			string res;
			for (int i=maxc-maxR+1; i<=maxc+maxR; i+=2)
				res += s0[i];

			return res;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
