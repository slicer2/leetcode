#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<vector<int> > generateMatrix(int n) {
			vector<vector<int> > result(n, vector<int> (n));

			int num = 1;

			int r = 0, c = -1;
			int r_lb = 0, r_ub = n;
			int c_lb = -1, c_ub = n;
			int dir = 0;
			int len;

			switch (dir) {
				case 0:
					len = c_ub - c - 1;
					break;
				case 1:
					len = r_ub - r - 1;
					break;
				case 2:
					len = c - c_lb - 1;
					break;
				default:
					len = r - r_lb - 1;
			}

			while (len > 0) {
				for (int i=0; i<len; i++)
					switch(dir) {
						case 0:
							result[r][++c] = num++;
							break;
						case 1:
							result[++r][c] = num++;
							break;
						case 2:
							result[r][--c] = num++;
							break;
						default:
							result[--r][c] = num++;
					}

				switch(dir) {
					case 0:
						c_ub = c;
						break;
					case 1:
						r_ub = r;
						break;
					case 2:
						c_lb = c;
						break;
					default:
						r_lb = r;
				}

				dir = (dir + 1) % 4;

				switch (dir) {
					case 0:
						len = c_ub - c - 1;
						break;
					case 1:
						len = r_ub - r - 1;
						break;
					case 2:
						len = c - c_lb - 1;
						break;
					default:
						len = r - r_lb - 1;
				}

			}

			return result;
		}
};

int main() {
	int n;

	cin >> n;

	Solution sol;

	cout << sol.generateMatrix(n) << endl;
	return 0;
}
