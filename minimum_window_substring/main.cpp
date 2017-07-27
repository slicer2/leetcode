#include "dan.h"
#include <climits>

using namespace std;

class Solution {
	public:
		string minWindow(string S, string T) {
			int total = T.size(), sz = S.size();
			vector<int> targetChars(128, 0), myChars(128, 0);

			for (auto x: T)
				targetChars[x]++;
			
			int p = 0, q = 0, minLen = INT_MAX, idx, myEffective = 0;
			myChars[S[0]]++;
			if (myChars[S[0]] <= targetChars[S[0]]) myEffective++;

			while (q < sz) {
				if (myEffective == total) {
					if (q-p+1<minLen) {
						minLen = q-p+1;
						idx = p;
					}

					myChars[S[p]]--;
					if (myChars[S[p]] < targetChars[S[p]])
						myEffective--;
					p++;
				}
				else {
					if (++q < sz)
						myChars[S[q]]++;
						if (myChars[S[q]] <= targetChars[S[q]])
							myEffective++;
				}
			}

			return (minLen == INT_MAX)?"":S.substr(idx, minLen);
		}
};


int main() {
	string s;
	string t;

	cin >> s;
	cin >> t;

	cerr << "S = " << s << endl;
	cerr << "T = " << t << endl;


	//priority_queue<int, vector<int>, greater<int> > test;

	//test.push(3);
	//test.push(1);
	//test.push(4);

	//cout << test.top() << endl;

	Solution sol;
		cout << sol.minWindow(s, t) << endl;
	return 0;
}
