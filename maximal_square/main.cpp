#include <iostream>
#include <vector>
#include "dan.h"


using namespace std;

class Solution {
	public:
		int maximalSquare(vector<vector<char>>& matrix) {
			vector<vector<int> > v1(matrix.size(), vector<int>(matrix[0].size(), 0)), h1(matrix.size(), vector<int>(matrix[0].size(), 0));
		}
};

int main() {
	vector<vector<char> > matrix;
	cin >> matrix;

	Solution sol;
	cout << sol.maximalSquare(matrix) << endl;

	return 0;
}
