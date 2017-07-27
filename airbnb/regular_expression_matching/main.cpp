#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

bool match(string s, string t) {
	int szs = s.size(), szt = t.size();

	if (szs == 0) {
		if (szt == 2 && t[1] == '*')
			return true;
		else
			return false;
	}


	vector<vector<bool>> dp(szs, vector<bool>(szt, false));

	switch (t[0]) {
		case '.':
			dp[0][0] = true;
			break;
		default:
			dp[0][0] = (s[0] == t[0]);
	}

	for (int i=1; i<szs; i++)
		dp[i][0] = false;

	if (szt == 1) return dp[szs-1][0];

	if (t[1] == '*')
		dp[0][1] = dp[0][0];
	else
		dp[0][1] = false;

	for (int j=2; j<szt; j++)
		dp[0][j] = false;

	vector<vector<bool>> accu = dp;

	for (int i=1; i<szs; i++) {
		for (int j=1; j<szt; j++) {
			switch (t[j]) {
				case '.':
					dp[i][j] = dp[i-1][j-1];
					break;
				case '*':
					dp[i][j] = dp[i][j-1] || ( s[i] == s[i-1] && accu[i-1][j-1] );
					break;
				case '+':
					dp[i][j] = (s[i] == s[i-1]) && accu[i-1][j-1];
					break;
				default:
					dp[i][j] = (dp[i-1][j-1] && (s[i] == t[j]));
			}

			accu[i][j] = ( dp[i][j] || (accu[i-1][j] && s[i] == s[i-1]) );
		}
	}

	return dp[szs-1][szt-1];
}

int main() {
	string s, t;
	cin >> s >> t;

	cout << match(s, t) << endl;
	return 0;
}
