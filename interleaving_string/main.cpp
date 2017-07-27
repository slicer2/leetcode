#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if (s3.length() != s1.length() + s2.length())
				return false;

			if (s1 == "")
				return s2 == s3;

			if (s2 == "")
				return s1 == s3;

			vector<bool> f(s1.length()+1);

			f[0] = true;

			for (int j=1; j<=(int)s1.length(); j++)
				f[j] = ( (s3[j-1] == s1[j-1]) & f[j-1] );

			cerr << f << endl;

			for (int i=1; i<=(int)s2.length(); i++) {

				bool prev = ( (s3[i-1] == s2[i-1]) & f[0] );
				
				for (int j=1; j<=(int)s1.length(); j++) {
					bool curr = ( ( (s3[i+j-1] == s2[i-1]) & f[j]) | ( (s3[i+j-1] == s1[j-1]) & prev) );
					f[j-1] = prev;
					prev = curr;
				}

				f[s1.length()] = prev;

				cerr << f << endl;
			}

			return f[s1.length()];
		}
};

int main() {
	string s1, s2, s3;

	cin >> s1;
	cin >> s2;
	cin >> s3;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	Solution sol;

	cout << ((sol.isInterleave(s1, s2, s3))?"yes":"no") << endl;
	return 0;
}
