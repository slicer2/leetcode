#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			vector<int> line;

			line.push_back(1);
			if (rowIndex == 0)
				return line;


			for (int i=1; i<rowIndex+1; i++) {
				int prev = line[0];
				int line_size = line.size();

				for (int j=1; j<line_size; j++) {
					int curr = line[j];
					line[j] = curr + prev;
					prev = curr;
				}

				line.push_back(1);
			}

			return line;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.getRow(n) << endl;
	return 0;
}
