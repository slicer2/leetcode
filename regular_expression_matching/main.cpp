#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <climits>
#include <cstdlib>
#include "dan.h"

using namespace std;

class Solution {
	struct Element {
		char base;
		int lower, upper;
	};

	typedef	vector<pair<unsigned, unsigned> > Partial;

	vector<Element> ap;
	const char *s;
	Partial partial;

	const char *retrieve(const char *p, char *s) {
		if (*p != '\0')
			s[0] = *p++;

		if (*p == '*') {
			s[1] = '*';
			p++;
		}

		return p;
	}

	vector<Element> analyze(const char *p) {
		vector<Element> result;

		while (*p != '\0') {
			Element e;
			char atomic[2] = {' '};

			p = retrieve(p, atomic);
			e.base = atomic[0];
			if (atomic[1] == '*') {
				e.lower = 0;
				e.upper = INT_MAX;
			}
			else {
				e.lower = 1;
				e.upper = 1;
			}

			atomic[0] = ' ';
			atomic[1] = ' ';
			const char *q = retrieve(p, atomic);
			while (atomic[0] == e.base) {
				if (atomic[1] == '*')
					e.upper = INT_MAX;
				else {
					e.lower++;
					e.upper = (e.upper == INT_MAX)?INT_MAX:(e.upper+1);
				}

				p = q;
				atomic[0] = ' ';
				atomic[1] = ' ';
				q = retrieve(p, atomic);
			}

			result.push_back(e);
		}

		return result;
	}

	bool bt(unsigned start) {
		if (partial.size() == ap.size()) {
			if (s[start] == '\0')
				return true;
			else
				return false;
		}

		int i;
		if (ap[partial.size()].base == '.') {
			for (i=0; i<ap[partial.size()].lower && s[i+start] != '\0'; i++);

			if (i != ap[partial.size()].lower)
				return false;

			for (; i<=ap[partial.size()].upper && (i == 0 || (s[i-1+start] != '\0')); i++) {
				partial.push_back(make_pair(start, i));
				if (bt(start+i))
					return true;

				partial.pop_back();
			}
		}
		else {
			for (i=0; i<ap[partial.size()].lower && s[i+start] == ap[partial.size()].base; i++);

			if (i != ap[partial.size()].lower)
				return false;

			for (; i<=ap[partial.size()].upper && (i == 0 || (s[i-1+start] != '\0' && s[i-1+start] == ap[partial.size()].base)); i++) {
				partial.push_back(make_pair(start, i));
				if (bt(start+i))
					return true;

				partial.pop_back();
			}
		}

		return false;
	}


	public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {
			if (*s == '\0')
				return true;
			else
				return false;
		}

		ap = analyze(p);

		//for (auto &x: ap)
		//	cerr << x.base << ' ' << x.lower << ' ' << x.upper << endl;

		this->s = s;

		return bt(0);
	}
};

int main() {
	char s[100], p[100];

	cin >> s >> p;

	Solution sol;

	cout << sol.isMatch(s, p) << endl;

	return 0;
}
