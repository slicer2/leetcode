#include <iostream>
using namespace std;


class Solution {
	public:
		int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int sum = (D-B)*(C-A)+(H-F)*(G-E);
			int left = max(A, E), right = min(C, G), bottom = max(B, F), top = min(D, H);

			if (left > right || bottom > top) return sum;
			else return sum - (right-left)*(top-bottom);
		}
};

int main() {
	int A, B, C, D, E, F, G, H;
	cin >> A >> B >> C >> D >> E >> F >> G >> H;

	Solution sol;
	cout << sol.computeArea(A, B, C, D, E, F, G, H) << endl;
	return 0;
}
