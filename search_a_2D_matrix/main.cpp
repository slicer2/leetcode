#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	int rows, cols;

	int r(int n) {
		return n / cols;
	}

	int c(int n) {
		return n % cols;
	}

	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target) {
			if (matrix.size() == 0 || matrix[0].size() == 0)
				return false;

			rows = matrix.size();
			cols = matrix[0].size();

			int start = 0, end = rows * cols;

			int mid = (start+end)/2;

			while (matrix[r(mid)][c(mid)] != target && start+1 < end) {
				if (matrix[r(mid)][c(mid)] < target)
					start = mid;
				else
					end = mid;

				mid = (start+end)/2;
			}

			if (matrix[r(mid)][c(mid)] == target)
				return true;

			return false;
		}
};

int main() {
	int target;
	vector<vector<int> > matrix;

	string s;
	int num;
	vector<int> row;

	cin >> target;
	getline(cin, s);


	while (getline(cin, s)) {
		stringstream ss(s);
		row.clear();

		while (ss >> num) {
			row.push_back(num);
		}

		matrix.push_back(row);
	}

	cout << "target = " << target << endl;
	cout << "matrix" << endl << matrix << endl;

	Solution sol;

	cout << ((sol.searchMatrix(matrix, target))?"yes":"no") << endl;

	return 0;
}
