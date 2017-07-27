#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <utility>

using namespace std;

template <typename T>
std::ostream & operator << (std::ostream &os, std::vector<T> &v) {
	typename std::vector<T>::iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it);

	return os; 
}

template <typename T>
std::ostream & operator << (std::ostream &os, std::vector<std::vector<T> > &v) {
	typename std::vector<std::vector<T> >::iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it) << std::endl;

	return os; 
}

class Solution {
	bool flip(unsigned int i, unsigned int j, vector<vector<char> > &board, vector<vector<int> > &seen, char ch, int visit_lim) {
		bool reachBorder = false;

		stack<pair<int, int> > toVisit;

		toVisit.push(make_pair(i, j));

		seen[i][j]++;

		while (!toVisit.empty()) {
			pair<int, int> loc = toVisit.top();

			toVisit.pop();

			board[loc.first][loc.second] = ch;

			if (loc.first == 0)
				reachBorder = true;
			else
				if (board[loc.first-1][loc.second] == 'O' && seen[loc.first-1][loc.second] < visit_lim){
					toVisit.push(make_pair(loc.first-1, loc.second));
					seen[loc.first-1][loc.second]++;
				}

			if (loc.first == board.size()-1)
				reachBorder = true;
			else
				if (board[loc.first+1][loc.second] == 'O' && seen[loc.first+1][loc.second] < visit_lim){
					toVisit.push(make_pair(loc.first+1, loc.second));
					seen[loc.first+1][loc.second]++;
				}

			if (loc.second == 0)
				reachBorder = true;
			else
				if (board[loc.first][loc.second-1] == 'O' && seen[loc.first][loc.second-1] < visit_lim){
					toVisit.push(make_pair(loc.first, loc.second-1));
					seen[loc.first][loc.second-1]++;
				}

			if (loc.second == board[0].size()-1)
				reachBorder = true;
			else
				if (board[loc.first][loc.second+1] == 'O' && seen[loc.first][loc.second+1] < visit_lim){
					toVisit.push(make_pair(loc.first, loc.second+1));
					seen[loc.first][loc.second+1]++;
				}

		}

		return reachBorder;
	}

	public:
	void solve(vector<vector<char>> &board) {
		vector<vector<int> > seen;

		seen.resize(board.size());

		for (unsigned int i=0; i<board.size(); i++) {
			seen[i].resize(board[i].size());

			for (unsigned int j=0; j<board[i].size(); j++)
				seen[i][j] = 0;
		}


		for (unsigned int i=0; i<board.size(); i++) {
			for (unsigned int j=0; j<board[i].size(); j++) {
				if (board[i][j] == 'O' && seen[i][j] == 0)
					if (!flip(i, j, board, seen, 'O', 1))
						flip(i, j, board, seen,'X', 2);
			}
		}
	}
};

int main() {
	int row;
	string s;

	cin >> row;

	vector<vector<char>> board(row);

	for (int i=0; i<row; i++) {

		cin >> s;

		board[i].resize( s.length() );

		copy(s.begin(), s.end(), board[i].begin());
	}

	Solution sol;

	cout << board << endl;

	sol.solve(board);

	cout << board;

	return 0;

}
