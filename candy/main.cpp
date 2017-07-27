#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int candy(vector<int> &ratings) {
			int sz = ratings.size();
			vector<int> alloc(sz);
			alloc[0] = 1;
			for (int i=1; i<sz; i++)
				if (ratings[i] > ratings[i-1]) alloc[i] = alloc[i-1]+1;
				else alloc[i] = 1;

			int sum = alloc[sz-1];
			for (int i=sz-2; i>=0; i--) {
				if (ratings[i] > ratings[i+1]) alloc[i] = max(alloc[i+1]+1, alloc[i]);
				sum += alloc[i];
			}

			return sum;
		}
};

int main() {
	int num;
	vector<int> ratings;

	while (cin >> num) {
		ratings.push_back(num);
	}


	Solution s;
	cout << s.candy(ratings) << endl;

	return 0;
}
