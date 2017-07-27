#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			if (m == 0 || n == 0)
				return 0;

			vector<int> memoized(n);

			for (int i=0; i<n; i++)
				memoized[i] = 1;

			for (int k=2; k<=m; k++) {
				int prev = 1, curr;

				for (int i=2; i<=n; i++) {
					curr = prev + memoized[i-1];
					memoized[i-2] = prev;
					prev = curr;
				}

				memoized[n-1] = curr;
			}

			return memoized[n-1];
		}
};

int main() {
	int m, n;

	cin >> m >> n;

	Solution sol;

	cout << sol.uniquePaths(m, n) << endl;

	return 0;
}
