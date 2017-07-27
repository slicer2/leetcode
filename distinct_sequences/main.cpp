#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int numDistinct(string S, string T) {
			if (S.length() < T.length() || T.length() == 0)
				return 0;

			int prev;

			vector<int> row;

			if (S[0] == T[0]) {
				row.push_back(1);
			}
			else
				row.push_back(0);

			for (int i=1; i<(int)S.length(); i++)
				if (S[i] == T[0])
					row.push_back(row.back()+1);
				else
					row.push_back(row.back());

			//cerr << row << endl;

			for (int j=1; j<(int)T.length(); j++) {

				prev = row[j];

				if (S.substr(0, j+1) == T.substr(0, j+1))
					row[j] = 1;
				else
					row[j] = 0;

				for (int i=j+1; i<(int)S.length(); i++) {
					int curr = row[i];
					row[i] = row[i-1];
					
					if (S[i] == T[j])
						row[i] += prev;

					prev = curr;
				}

				//cerr << row << endl;
			}

			return row.back();
		}
};

int main() {
	string s, t;

	cin >> s;
	cin >> t;

	Solution sol;

	cerr << s << endl
		<< t << endl
		<< sol.numDistinct(s, t) << endl;
	return 0;
}
