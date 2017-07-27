#include <string>
#include <iostream>
#include "dan.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			vector<string> result;
			int flag[1048576] = {0};

			if (s.length() < 10)
				return result;

			unsigned i4=0;
			for (unsigned i=0; i<10; i++)
				switch (s[i]) {
					case 'A':
						i4 = 4*i4;
						break;
					case 'C':
						i4 = 4*i4+1;
						break;
					case 'G':
						i4 = 4*i4+2;
						break;
					default:
						i4 = 4*i4+3;
				}
				

			flag[i4]++;

			for (unsigned i=10; i<=s.length(); i++) {
				switch(s[i-10]) {
					case 'A':
						break;
					case 'C':
						i4 -= 262144;
						break;
					case 'G':
						i4 -= 2*262144;
						break;
					default:
						i4 -= 3*262144;
				}

				switch(s[i]) {
					case 'A':
						i4 = 4*i4;
						break;
					case 'C':
						i4 = 4*i4+1;
						break;
					case 'G':
						i4 = 4*i4+2;
						break;
					default:
						i4 = 4*i4+3;
				}

				flag[i4]++;

				if (flag[i4] == 2)
					result.push_back(s.substr(i-9, 10));
			}

			return result;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.findRepeatedDnaSequences(s) << endl;
	return 0;
}
