#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			vector<vector<int> > result;

			if (numRows == 0)
				return result;

			vector<int> line;

			line.push_back(1);
			result.push_back(line);

			if (numRows == 1)
				return result;
			else
				for (int i=1; i<numRows; i++) {
					int line_size = line.size();
					int prev = line[0];

					for (int j=1; j<(int)line_size+1; j++) {

						if (j<(int)line_size) {
							int curr = line[j];
							line[j] = prev + curr;
							prev = curr;
						}
						else
							line.push_back(1);
					}

					result.push_back(line);
				}

			return result;
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout<< sol.generate(n) << endl;

	return 0;
}
