#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	int min(int x, int y) { return ((x<y)?x:y); }

	public:
	int minDistance(string word1, string word2) {
		if (word1.length() == 0)
			return word2.length();

		if (word2.length() == 0)
			return word1.length();

		vector<int> row(word2.length()+1);

		for (int i=0; i<=(int)word2.length(); i++)
			row[i] = i;

		//cerr << row << endl;

		int prev, curr;
		for (int j=1; j<=(int)word1.length(); j++) {
			prev = j;

			for (int i=1; i<=(int)word2.length(); i++) {
				if (word2[i-1] == word1[j-1]) {
					curr = row[i-1];
				}
				else {
					curr = min(prev, row[i-1]);
					curr = min(curr, row[i]) + 1;
				}

				row[i-1] = prev;
				prev = curr;
			}

			row[word2.length()] = prev;

			//cerr << row << endl;
		}

		return row[word2.length()];
	}
};

int main() {
	string word1, word2;
	cin >> word1 >> word2;

	Solution sol;

	cout << sol.minDistance(word1, word2) << endl;

	return 0;
}
