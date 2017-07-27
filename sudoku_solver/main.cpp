#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "dan.h"
#include <cstdlib>
#include <cassert>

using namespace std;

string indent=("");

ostream & operator << (ostream &os, const pair<int, int> &p) {
	os << '(' << p.first << ", " << p.second << ')';

	return os;
}

class Solution {
	int n_fillin;

	unordered_set<char> row[9], column[9], subgrid[9];

	vector<pair<int, int> > loc_fillin;

	void prepSolver(vector<vector<char> > &board){
		n_fillin = 0;

		for (int i=0; i<9; i++)
			for (int j=0; j<9; j++)
				if (board[i][j] != '.') {
					row[i].insert(board[i][j]);
					column[j].insert(board[i][j]);
					subgrid[(i/3)*3+(j/3)].insert(board[i][j]);
				}
				else {
					loc_fillin.push_back(make_pair(i, j));
					n_fillin++;
				}

		//cerr << n_fillin;
		//cerr << loc_fillin << endl;
	}

	void update(vector<char> &fillin, bool action){
		/* true for addition, false for removal */

		if (fillin.empty()) return;

		pair<int, int> p = loc_fillin[fillin.size()-1];
		int i = p.first, j = p.second;
		char fill = fillin.back();

		if (action) {
			row[i].insert(fill);
			column[j].insert(fill);
			subgrid[(i/3)*3+(j/3)].insert(fill);
		}
		else {
			row[i].erase(fill);
			column[j].erase(fill);
			subgrid[(i/3)*3+(j/3)].erase(fill);
		}
	}

	bool isValid (vector<char> &fillin) {
		if (fillin.empty()) return true;

		pair<int, int> p = loc_fillin[fillin.size()-1];
		int i = p.first, j = p.second;
		char fill = fillin.back();

		if (row[i].find(fill) == row[i].end() &&
				column[j].find(fill) == column[j].end() &&
				subgrid[(i/3)*3+(j/3)].find(fill) == subgrid[(i/3)*3+(j/3)].end())

			return true;
		else
			return false;
	}

	bool bt(vector<char> &fillin) {
		//indent += "  ";
		//cerr << fillin << endl;
		//indent = indent.substr(0, indent.size()-2);

		if (!isValid(fillin)) return false;

		update(fillin, true);

		if (n_fillin == (int)fillin.size()) return true;

		for (char i='1'; i<='9'; i++) {
			fillin.push_back(i);
			if (bt(fillin))
				return true;

			fillin.pop_back();
		}

		update(fillin, false);

		return false;
	}

	public:
	void solveSudoku(vector<vector<char> > &board) {
		vector<char> fillin;

		prepSolver(board);

		if (bt(fillin)) {
			assert(fillin.size() == loc_fillin.size());

			for (int i=0; i<(int)loc_fillin.size(); i++)
				board[loc_fillin[i].first][loc_fillin[i].second] = fillin[i];
		}
	}
};

int main() {
	string row;
	vector<vector<char> > board;

	for (int i=0; i<9; i++) {
		cin >> row;

		vector<char> r(row.begin(), row.end());
		board.push_back(r);
	}

	Solution sol;

	sol.solveSudoku(board);

	cout << board << endl;

	return 0;
}
