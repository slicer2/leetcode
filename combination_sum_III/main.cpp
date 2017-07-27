#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	private:
		int k, n;
		vector<vector<int> > res;

	public:
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<int> partial(9, 0);
			int sum = 0, num = 0, choice = 0;
			this->k = k;
			this->n = n;

			bt(partial, sum, num, choice);

			return res;
		}

		void bt(vector<int> &partial, int sum, int num, int choice) {

			if (num > k || sum > n)
				return;

			if (num == k) {
				if (sum == n) {
					vector<int> temp;
					for (int i=0; i<9; i++)
						for (int j=0; j<partial[i]; j++)
							temp.push_back(i+1);

					res.push_back(temp);
				}
				
				return;
			}
			else if (sum == n)
				return;

			for (int i=choice; i<9; i++) {
				if (partial[i] == 0) {
					partial[i]++;
					bt(partial, sum+i+1, num+1, i);
					partial[i]--;
				}
			}
		}
};

int main() {
	int k, n;
	cin >> k >> n;

	Solution sol;
	cout << sol.combinationSum3(k, n) << endl;
	return 0;
}
