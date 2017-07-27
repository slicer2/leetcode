#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		bool isValidSudoku(vector<vector<char> > &board) {
			for (int i=0; i<9; i++) {
				vector<int> fill(9, 0);

				for (int j=0; j<9; j++)
					if (board[i][j] != '.') {
						if (fill[board[i][j]-'1'] == 1) {
							cerr << "1 - " << i << "  " << j << endl;
							return false;
						}
						else
							fill[board[i][j]-'1'] = 1;
					}
			}

			for (int i=0; i<9; i++) {
				vector<int> fill(9, 0);

				for (int j=0; j<9; j++)
					if (board[j][i] != '.') {
						if (fill[board[j][i]-'1'] == 1) {
							cerr << "2 - " << i << "  " << j << endl;
							cerr << board[j][i] << endl;
							return false;
						}
						else
							fill[board[j][i]-'1'] = 1;
					}
			}

			for (int i=0; i<9; i++) {
				vector<int> fill(9, 0);

				for (int j=0; j<9; j++)
					if (board[(i/3)*3+j/3][(i%3)*3+j%3] != '.') {
						if (fill[board[(i/3)*3+j/3][(i%3)*3+j%3]-'1'] == 1) {
							cerr << "3 - " << i << "  " << j << endl;
							return false;
						}
						else
							fill[board[(i/3)*3+j/3][(i%3)*3+j%3]-'1'] = 1;
					}
			}

			return true;
		}
};

int main() {
	vector<vector<char> > board;

	cin >> board;
	cout << board << endl;

	Solution sol;
	cout << sol.isValidSudoku(board) << endl;

	return 0;
}
