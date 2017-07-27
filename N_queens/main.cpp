#include <iostream>
#include <vector>
#include <cstdlib>
#include "dan.h"

using namespace std;

ostream & operator << (ostream &os, const vector<vector<string> > &v){
	for (auto &x: v) {
		for (auto &y: x) {
			os << y << endl;
		}

		os << endl;
	}

	return os;
}

class Solution {
	bool valid(vector<int> &s) {
		if (s.size() <= 1)
			return true;


		for (int i=1; i<(int)s.size(); i++) {
			for (int j=0; j<i; j++) {
				if ( (i-j+s[i]-s[j] == 0) || (i-j-s[i]+s[j] == 0) )
					return false;
			}
		}

		return true;
	}

	void bt(vector<int> &s, vector<vector<string> > &res, vector<bool> &occupied, int &n){
		bool check = valid(s);

		if (!check) return;

		if (check && (int)s.size() == n) {
			cerr << "bingo: " << s << endl;

			vector<string> config;
			for (int i=0; i<n; i++) {
				string row(n, '.');

				row[s[i]] = 'Q';
				config.push_back(row);
			}

			res.push_back(config);
			return;
		}

		int i=0;
		for (; i< n && occupied[i]; i++);

		while (i < n) {
			s.push_back(i);
			occupied[i] = true;

			//cerr << s << endl;

			bt(s, res, occupied, n);

			s.pop_back();
			occupied[i] = false;
			i++;
			for (; i<n && occupied[i]; i++);
		}
	}

	public:
		vector<vector<string> > solveNQueens(int n) {
			vector<vector<string> > result;
			vector<int> s;
			vector<bool> occupied(n, false);

			bt(s, result, occupied, n);

			return result;
		}
};

int main() {
	int n;
	cin >> n;
	Solution sol;

	vector<vector<string> > conf = sol.solveNQueens(n);

	cout << conf << endl;

	cout << conf.size() << endl;

	return 0;
}
