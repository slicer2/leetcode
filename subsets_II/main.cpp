 
#include <iostream>
#include <vector>
#include "dan.h"
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<vector<int> > subsetsWithDup(vector<int> &S) {
			sort(S.begin(), S.end());
			vector<vector<int> > result;
			result.push_back(vector<int>(0));
			int result_size;
			int start;

			for (int i=0; i<(int)S.size(); i++) {
				if (i>0 && S[i] == S[i-1])
					start = result.size() - (result_size-start);
				else
					start = 0;

				result_size = result.size();

				for (int j=start; j<result_size; j++) {
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

	cout << sol.subsetsWithDup(S) << endl;

	return 0;
}
