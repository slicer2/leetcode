#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include "dan.h"
#include <string>

using namespace std;


string ind("");

ostream & operator << (ostream &os, const pair<int, int> &p) {
	os << '(' << p.first << ", " << p.second << ')';

	return os;
}

class Solution {
	int largest(vector<int> &height, int start, int end) {
		//ind += "  ";
		//cerr << ind << "start = " << start << "  end = " << end << endl;

		if (end == start + 1) {
			//ind = ind.substr(0, ind.length()-2);
			return height[start];
		}

		int areaLeft = largest(height, start, (start+end)/2);
		int areaRight = largest(height, (start+end)/2, end);

		//cerr << ind << "areaLeft = " << areaLeft << "  areaRight = " << areaRight << endl;

		vector<pair<int, int> > rampLeft, rampRight;

		int currMaxHeight = height[(start+end)/2-1];

		for (int i=(start+end)/2-2; i>=start; i--) {
			if (height[i] < currMaxHeight) {
				rampLeft.push_back(make_pair(currMaxHeight, i+1));
				currMaxHeight = height[i];
			}
		}

		rampLeft.push_back(make_pair(currMaxHeight, start));

		//cerr << ind << "rampLeft:" << endl;
		//cerr << ind << rampLeft << endl;

		currMaxHeight = height[(start+end)/2];

		for (int i=(start+end)/2+1; i<end; i++) {
			if (height[i] < currMaxHeight) {
				rampRight.push_back(make_pair(currMaxHeight, i-1));
				currMaxHeight = height[i];
			}
		}

		rampRight.push_back(make_pair(currMaxHeight, end-1));

		//cerr << ind << "rampRight:" << endl;
		//cerr << ind << rampRight << endl;

		int p = 0, q = 0;
		int area, maxArea = -1;
		while (p < (int)rampLeft.size() || q < (int)rampRight.size()) {
			if (p == (int)rampLeft.size()) {
				area = rampRight[q].first * (rampRight[q].second-start+1);

				if (maxArea < area)
					maxArea = area;

				q++;
			}
			else 
				if (q == (int)rampRight.size()) {
					area = rampLeft[p].first * (end-rampLeft[p].second);

					if (maxArea < area)
						maxArea = area;

					p++;
				}
				else {
					if (rampLeft[p].first < rampRight[q].first) {
						if (p == 0)
							area = rampRight[q].first * (rampRight[q].second - (start+end)/2 + 1);
						else
							area = rampRight[q].first * (rampRight[q].second - rampLeft[p-1].second + 1);

						if (maxArea < area)
							maxArea = area;

						q++;
					}
					else 
						if (rampLeft[p].first > rampRight[q].first) {
							if (q == 0)
								area = rampLeft[p].first * ((start+end)/2 - rampLeft[p].second);
							else
								area = rampLeft[p].first * (rampRight[q-1].second - rampLeft[p].second + 1);

							if (maxArea < area)
								maxArea = area;

							p++;
						}
						else {
							area = rampRight[q].first * (rampRight[q].second - rampLeft[p].second + 1);

							if (maxArea < area)
								maxArea = area;

							p++;
							q++;
						}
				}

			//cerr << ind << "p = " << p << "  q = " << q << "  maxArea = " << maxArea << endl;
		}


		if (areaLeft > maxArea)
			maxArea = areaLeft;

		if (areaRight > maxArea)
			maxArea = areaRight;

		//ind = ind.substr(0, ind.length()-2);
		return maxArea;
	}

	public:
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0)
			return 0;

		return largest(height, 0, height.size());
	}
};

int main() {
	vector<int> height;
	int h;

	while (cin >> h) 
		height.push_back(h);

	Solution sol;

	cout << sol.largestRectangleArea(height) << endl;

	return 0;
}
