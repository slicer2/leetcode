 
#include <iostream>
#include <vector>
#include "dan.h"
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<vector<int> > subsets(vector<int> &S) {
			sort(S.begin(), S.end());
			vector<vector<int> > result;
			result.push_back(vector<int>(0));

			for (int i=0; i<(int)S.size(); i++) {

				int result_size = result.size();

				for (int j=0; j<result_size; j++) {
					vector<int> t = result[j];
					t.push_back(S[i]);
					result.push_back(t);
				}
			}

			return result;
		}
};

int main() {
	int n;

	vector<int> S;

	cin >> n;

	for (int i=0; i<n; i++) {
		S.push_back(i+2);
		S.push_back(i+2);
	}

	Solution sol;

	cout << sol.subsets(S) << endl;

	return 0;
}
