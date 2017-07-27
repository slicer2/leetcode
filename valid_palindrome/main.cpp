#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool isPalindrome(string s) {
			int sz = s.size();
			int p = 0, q = sz-1;
			while (p < q) {
				while (p<q && !isalnum(s[p])) p++;
				while (p<q && !isalnum(s[q])) q--;
				if (p < q) {
					if (tolower(s[p]) != tolower(s[q])) return false;
					else {p++; q--;}
				}
			}
			
			return true;
		}
};

int main() {
	string s;

	getline(cin, s);

	Solution sol;
	cout << ( (sol.isPalindrome(s))? "yes":"no" ) << endl;
	return 0;
}

