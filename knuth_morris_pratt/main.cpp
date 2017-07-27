#include <iostream>
#include <string>
#include <cassert>
#include "dan.h"

using namespace std;

vector<int> kmp(const string p) {
	assert(p.length() > 0);

	vector<int> pi(p.length());

	pi[0] = 0;
	
	int q = 0;

	for (int i=1; i<(int)p.length(); i++) {
		while (q > 0 && p[i] != p[q])
			q = pi[q-1];

		if (p[i] == p[q])
			q++;

		pi[i] = q;
	}

	return pi;
}

vector<int> match(const string &s, const string &p) {
	vector<int> res;

	vector<int> pi = kmp(p);

	int q = 0;

	for (int i=0; i<(int)s.length(); i++) {
		while (q > 0 && s[i] != p[q])
			q = pi[q-1];

		if (s[i] == p[q])
			q++;

		if (q == (int)p.length()) {
			res.push_back(i-p.length()+1);
			q = pi[q-1];
		}
	}

	return res;
}

int main() {
	string s, p;

	cin >> s >> p;

	//cout << "s = " << s << endl;
	//cout << "p = " << p << endl;

	cout << match(s, p) << endl;
	return 0;
}
