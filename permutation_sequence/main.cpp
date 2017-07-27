#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "dan.h"

using namespace std;

string ind("");

class Solution {
	public:
	string getPermutation(int n, int k) {
		set<int> st;
		int fact = 1;
		for (int i=1; i<=n; i++) {
			st.insert(i);
			fact *= i;
		}

		k--;
		string s;
		while (!st.empty()) {
			fact /= st.size();
			int q = k / fact;
			k %= fact;

			auto it = st.begin();
			advance(it, q);

			s += to_string(*it);
			st.erase(it);
		}

		return s;
	}
};

int main() {
	int n, k;

	cin >> n >> k;

	Solution sol;

	cout << sol.getPermutation(n, k) << endl;

	return 0;
}
