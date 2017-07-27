#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "dan.h"

using namespace std;

class Solution {
	struct mySort{
		bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) const {
			return (p1.second < p2.second);
		}
	};

	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			int i=1;
			vector<pair<int, int> > numbersWithIdx;

			for (auto &x: numbers)
				numbersWithIdx.push_back(make_pair(i++, x));

			sort(numbersWithIdx.begin(), numbersWithIdx.end(), mySort());

			i = 0;
			int j = numbersWithIdx.size()-1;

			for (; i< j; i++) {
				while (j > i && numbersWithIdx[j].second > target - numbersWithIdx[i].second)
					j--;

				if (numbersWithIdx[j].second == target - numbersWithIdx[i].second) {
					int idx1 = numbersWithIdx[i].first;
					int idx2 = numbersWithIdx[j].first;

					if (idx1 < idx2)
						return vector<int> ( {idx1, idx2} );
					else
						return vector<int> ( {idx2, idx1} );
				}
			}

			return vector<int> ( { -1, -1 } );
		}
};

int main() {
	vector<int> numbers;
	int target;

	cin >> target;

	cin.ignore(100, '\n');

	cin >> numbers;

	Solution sol;

	cout << sol.twoSum(numbers, target) << endl;

	return 0;
}
