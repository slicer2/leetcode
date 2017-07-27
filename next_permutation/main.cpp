#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {

	public:
		void nextPermutation(vector<int> &num) {
			if (num.size() <= 1)
				return;

			unsigned i;
			for (i=num.size()-1; i>=1 && num[i] <= num[i-1]; i--);

			if (i > 0) {
				unsigned start = i, end = num.size();

				while (start+1 < end) {
					int mid = (start+end)/2;
					
					if (num[mid] > num[i-1])
						start = mid;
					else
						end = mid;
				}

				int t = num[i-1];
				num[i-1] = num[start];
				num[start] = t;

				unsigned j, k;
				for (j=i, k=num.size()-1; j < k; j++, k--) {
					int t = num[j];
					num[j] = num[k];
					num[k] = t;
				}
			}
			else {
				unsigned j, k;
				for (j=0, k=num.size()-1; j < k; j++, k--) {
					int t = num[j];
					num[j] = num[k];
					num[k] = t;
				}
			}
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;

	sol.nextPermutation(num);
	cout << num << endl;
	return 0;
}
