#include <iostream>
#include <stack>
#include <utility>
#include "dan.h"

using namespace std;

ostream & operator << (ostream &os, const pair<int, int> &p) {
	os << p.first << '\t' << p.second;
	return os;
}

class Solution {
	public:
		int trap(int A[], int n) {

			if (n==0)
				return 0;

			int *area = new int[n];
			int *maxWater = new int[n];

			area[0] = A[0];
			maxWater[0] = 0;

			stack<pair<int, int> > leftRamp;

			leftRamp.push(make_pair(A[0], 0));

			cerr << "bar" << '\t' << "area" << '\t' << "mWat" << endl;			
			cerr << A[0] << '\t' << area[0] << '\t' << maxWater[0] << endl;
			pair<int, int> nextHigh;
			for (int i=1; i<n; i++) {

				area[i] = area[i-1] + A[i];

				while (!leftRamp.empty() && A[i] >= leftRamp.top().first) {
					nextHigh = leftRamp.top();
					leftRamp.pop();
				}

				if (!leftRamp.empty()) {
					int leftBound = leftRamp.top().second;
					maxWater[i] = maxWater[leftBound]
						+ A[i] * (i-leftBound) 
						- (area[i] - area[leftBound]);
				}
				else {
					int leftBound = nextHigh.second;
					maxWater[i] = maxWater[leftBound]
						+ A[leftBound] * (i-1-leftBound)
						- (area[i-1] - area[leftBound]);
				}

				leftRamp.push(make_pair(A[i], i));

				cerr << A[i] << '\t' << area[i] << '\t' << maxWater[i] << endl;
			}

			return maxWater[n-1];
		}
};

int main() {
	int n;

	cin >> n;

	int *A = new int[n];

	for (int i=0; i<n; i++) cin >> A[i];

	for (int i=0; i<n; i++) cerr << A[i] << ' ';
	cerr << endl;

	Solution sol;

	cout << sol.trap(A,n) << endl;
}
