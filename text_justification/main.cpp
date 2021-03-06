/**
 * OJ wants extra spaces to be allocated to the first few
 * dividers (string of spaces), instead of dispersing them
 * as evenly as possible among dividers.
 * 
 * This version implements what OJ wants.
 */
 
#include <iostream>
#include <vector>
#include <sstream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<string> fullJustify(vector<string> &words, int L) {
			vector<string> justified;

			if (words.empty())
				return justified;

			vector<string>::iterator it = words.begin();

			int totalChar = 0;
			int totalDiv = 0;
			vector<string> row;

			while (it != words.end()) {
				if (row.empty()){
					row.push_back(*it);
					totalChar += it->length();

					it++;
				}
				else {
					string line("");

					if (totalChar + totalDiv + 1 + (int)it->length() <= L) {
						row.push_back(*it);
						totalChar += it->length();
						totalDiv++;

						it++;
					}
					else {
						if (totalDiv == 0)
							line += row.front() + string(L-totalChar, ' ');
						else {
							int spaces = L - totalChar;
							int eachDivHasSpace = spaces / totalDiv;
							int extraSpace = spaces % totalDiv;
							

							vector<string>::iterator it = row.begin();
							line += (*it++);

							int divIdx = 0, usedExtra = 0;
							for (; it != row.end(); it++) {
								if (usedExtra < extraSpace)
									line += string(eachDivHasSpace+1, ' ');
								else
									line += string(eachDivHasSpace, ' ');

								divIdx++;
								usedExtra++;

								line += (*it);
							}
						}

						row.clear();
						totalChar = 0;
						totalDiv = 0;

						justified.push_back(line);
					}
				}
			}

			if (!row.empty()) {
				vector<string>::iterator it = row.begin();
				string line("");
				line += (*it++);

				for (; it != row.end(); it++) {
					line += " " + (*it);
				}

				line += string(L - totalChar - totalDiv, ' ');

				justified.push_back(line);
			}

			return justified;
		}
};

int main() {
	vector<string> words;
	int L;

	string word, s;

	cin >> L;

	while (getline(cin, s)) {
		stringstream ss(s);

		while (ss >> word)
			words.push_back(word);
	}

	Solution sol;

	vector<string> result = sol.fullJustify(words, L);
	
	for (auto &x: result)
		cout << x << endl;

	return 0;
}
