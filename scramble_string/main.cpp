#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>


using namespace std;

string indent("");

class Solution {
	typedef unordered_map<int, unordered_map<int, unordered_map<int, bool > > > Record;
	Record record;

	bool is_scramble(string &s1, int start_1, int len, string &s2, int start_2) {
		if (len == 0) return true;

		//indent += "  ";
		//cerr << indent << "compare " << s1.substr(start_1, len) << "   " << s2.substr(start_2, len) << endl;

		bool result = false;

		Record::iterator it = record.find(start_1);

		if (it != record.end()) {
			unordered_map<int, unordered_map<int, bool> >::iterator it2 = it->second.find(len);
			if (it2 != it->second.end()) {
				unordered_map<int, bool>::iterator it3 = it2->second.find(start_2);
				if (it3 != it2->second.end()) {
					//cerr << indent << ((it3->second)?"yes":"no") << endl;
					//indent = indent.substr(0, indent.length()-2);
					return it3->second;
				}
			}
		}


		char unmatch[128] = {0};
		int count_unmatch = 0;

		if (len == 1 && s1[start_1] == s2[start_2])
			result = true;

		if (!result) {
			for (int i=0; i<len-1; i++) {
				if (unmatch[ (unsigned) s1[start_1+i] ] < 0)
					count_unmatch--;
				else
					count_unmatch++;

				unmatch[ (unsigned) s1[start_1+i] ]++;

				if (unmatch[ (unsigned) s2[start_2+i] ] > 0)
					count_unmatch--;
				else
					count_unmatch++;

				unmatch[ (unsigned) s2[start_2+i] ]--;


				if (count_unmatch == 0) {
					//cerr << indent << "further inorder compare " << s1.substr(start_1, i+1) << "   " << s2.substr(start_2, i+1) << endl;
					//cerr << indent << "further inorder compare " << s1.substr(start_1+i+1, len-i-1) << "   " << s2.substr(start_2+i+1, len-i-1) << endl;
					if (is_scramble(s1, start_1, i+1, s2, start_2) && len-i-1 > 0 && is_scramble(s1, start_1+i+1, len-i-1, s2, start_2+i+1)) {
						result = true;
						break;
					}
				}
			}
		}

		if (!result) {
			count_unmatch = 0;
			for (int i=0; i<128; i++) unmatch[i] = 0;

			for (int i=0; i<len-1; i++) {
				if (unmatch[ (unsigned) s1[start_1+i] ] < 0)
					count_unmatch--;
				else
					count_unmatch++;

				unmatch[ (unsigned) s1[start_1+i] ]++;

				if (unmatch[ (unsigned) s2[start_2+len-1-i] ] > 0)
					count_unmatch--;
				else
					count_unmatch++;

				unmatch[ (unsigned) s2[start_2+len-1-i] ]--;


				if (count_unmatch == 0) {
					//cerr << indent << "further reverse order compare " << s1.substr(start_1, i+1) << "   " << s2.substr(start_2+len-1-i, i+1) << endl;
					//cerr << indent << "further reverse order compare " << s1.substr(start_1+i+1, len-i-1) << "   " << s2.substr(start_2, len-i-1) << endl;
					if (is_scramble(s1, start_1, i+1, s2, start_2+len-1-i) && len-i-1 > 0 && is_scramble(s1, start_1+i+1, len-i-1, s2, start_2))
						result = true;
				}
			}
		}

		record[start_1][len][start_2] = result;

		//cerr << indent << ((result)?"yes":"no") << endl;
		//indent = indent.substr(0, indent.length()-2);
		return result;
	}

	public:

	bool isScramble(string s1, string s2) {

		if (s1.length() != s2.length()) return false;

		if (s1 == "") return true;

		return is_scramble(s1, 0, s1.length(), s2, 0);
	}
};

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	Solution sol;
	cout << ((sol.isScramble(s1, s2))?"yes":"no") << endl;
	return 0;
}
