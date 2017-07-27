#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
	struct Elem {
		char ch;
		int row;
		int col;
		Elem(char c, int r, int co): ch(c), row(r), col(co) {}
	};

	struct mySort {
		bool operator() (const Elem &e1, const Elem &e2) const {
			return (e1.row < e2.row || (e1.row == e2.row && e1.col < e2.col));
		}
	};

	public:
	string convert(string s, int nRows) {
		if (nRows == 1)
			return s;

		int row = 0, col = 0;
		vector<Elem> grid;

		/* 0 for zig (down), 1 for zag (up) */
		int state = 0;

		for (auto &x: s) {
			//cerr << x << '\t' << row << '\t' << col << endl;

			grid.push_back(Elem(x, row, col));

			if (state == 0) {
				row++;
				if (row == nRows) {
					row -= 2;
					col++;
					state = 1;
				}
			}
			else {
				row--;
				col++;
				if (row == -1) {
					row += 2;
					col--;
					state = 0;
				}
			}
		}

		sort(grid.begin(), grid.end(), mySort());

		string res;
		for (auto &x: grid)
			res += x.ch;

		return res;
	}
};

int main() {
	string s;
	int nRows;

	cin >> s >> nRows;

	Solution sol;

	cout << sol.convert(s, nRows) << endl;
	return 0;
}
