#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "dan.h"
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution {
	public:
		bool exist(vector<vector<char> > &board, string word) {
			string partial;
			if (word == "") return true;
			int r = board.size();
			if (r == 0) return false;
			int c = board[0].size();

			vector<vector<bool>> used(r, vector<bool>(c, false));
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++) {
					partial.push_back(board[i][j]);
					used[i][j] = true;
					if (bt(partial, board, used, i, j, word, 0)) return true;
					used[i][j] = false;
					partial.pop_back();
				}

			return false;
		}

		bool bt(string &partial, vector<vector<char>> &board, vector<vector<bool>> &used, int i, int j, string &word, int pos) {
			if (word[pos] == partial.back()) {
				if (pos == word.size()-1) return true;
			}
			else
				return false;

			if (i>0 && !used[i-1][j]) {
				used[i-1][j] = true;
				partial.push_back(board[i-1][j]);
				if (bt(partial, board, used, i-1, j, word, pos+1)) return true;
				partial.pop_back();
				used[i-1][j] = false;
			}
			if (i+1<board.size() && !used[i+1][j]) {
				used[i+1][j] = true;
				partial.push_back(board[i+1][j]);
				if (bt(partial, board, used, i+1, j, word, pos+1)) return true;
				partial.pop_back();
				used[i+1][j] = false;
			}
			if (j>0 && !used[i][j-1]) {
				used[i][j-1] = true;
				partial.push_back(board[i][j-1]);
				if (bt(partial, board, used, i, j-1, word, pos+1)) return true;
				partial.pop_back();
				used[i][j-1] = false;
			}
			if (j+1<board[0].size() && !used[i][j+1]) {
				used[i][j+1] = true;
				partial.push_back(board[i][j+1]);
				if (bt(partial, board, used, i, j+1, word, pos+1)) return true;
				partial.pop_back();
				used[i][j+1] = false;
			}

			return false;
		}
};

int main() {
	vector<vector<char> > board;
	string word;
	string s;
	char ch;
	vector<char> row;

	cin >> word;

	getline(cin, s);

	while (getline(cin, s)) {
		stringstream ss(s);
		row.clear();

		while (ss >> ch)
			row.push_back(ch);

		board.push_back(row);
	}

	//cout << "word = " << word << endl;
	//cout << "board = " << board << endl;

	Solution sol;

	cout << ((sol.exist(board, word))?"yes":"no") << endl;

	return 0;
}
