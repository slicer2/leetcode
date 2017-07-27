#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		bool isMatch(string str, string pat) {
			if (pat == "") return (str == "");

			int szs = str.size(), szt = pat.size();
			vector<vector<bool>> dp(szs+1, vector<bool>(szt, false)), accu(szs+1, vector<bool>(szt, false));

			switch (pat[0]) {
				case '*':
					dp[0][0] = true;
						break;
				case '?':
				default:
					dp[0][0] = false;
			}

			accu[0][0] = dp[0][0];

			for (int j=1; j<szt; j++) {
				switch (pat[j]) {
					case '*':
						dp[0][j] = dp[0][j-1];
						break;
					case '?':
					default:
						dp[0][j] = false;
				}

				accu[0][j] = dp[0][j];
			}

			for (int i=1; i<szs+1; i++) {
				switch (pat[0]) {
					case '*':
						dp[i][0] = true;
						break;
					case '?':
						dp[i][0] = (i==1);
						break;
					default:
						dp[i][0] = (i==1 && str[0] == pat[0]);
				}

				accu[i][0] = dp[i][0] || accu[i-1][0];

				for (int j=1; j<szt; j++) {
					switch (pat[j]) {
						case '*':
							dp[i][j] = accu[i][j-1];
							break;
						case '?':
							dp[i][j] = dp[i-1][j-1];
							break;
						default:
							dp[i][j] = (str[i-1] == pat[j] && dp[i-1][j-1]);
					}

					accu[i][j] = (accu[i-1][j] || dp[i][j]);
				}
			}

			return dp[szs][szt-1];
		}
};

int main() {
	string str, pat;
	cin >> str >> pat;

	cout << "str = " << str << "    pat = " << pat << endl;

	Solution sol;

	cout << sol.isMatch(str.c_str(), pat.c_str()) << endl;

	return 0;
}
