#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int> > &matrix) {

		}
};

int main() {
	string s;
	vector<vector<int> > matrix;

	while( getline(cin, s)) {
		stringstream ss(s);
		vector<int> row;
		int n;

		while (ss >> n)
			row.push_back(n);

		matrix.push_back(row);
	}

	Solution sol;

	sol.setZeros(matrix);

	cout << matrix << endl;

	return 0;
}
