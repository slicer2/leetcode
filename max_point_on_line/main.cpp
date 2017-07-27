#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
	Point() { x = 0; y = 0; }
	Point(int a, int b) { x = a; y = b; }
};

class Solution {

	struct Line {
		private:
			int gcd(int x, int y) {
				while (x != 0) {
					int t = x; x = y % x; y = t;
				}

				return y;
			}
		public:
			int a, b, c;
			Line(int a_in, int b_in, int c_in) {
				if (a_in != 0 || b_in != 0) {
					int g = gcd(a_in, gcd(b_in, c_in));
					a = a_in / g; b = b_in / g; c = c_in / g;
				}
				else {
					a = a_in; b = b_in; c = c_in;
				}

				if (a < 0) {
					a = -a; b = -b; c = -c;
				}
				else {
					if (a == 0 && b < 0) {
						b = -b; c = -c;
					}
					else {
						if (a == 0 && b == 0 && c < 0)
							c = -c;
					}
				}
			}
	};

	struct myHash {
		size_t operator() (const Line &l) const {
			hash<int> h;
			return h(l.a)+h(l.b)+h(l.c);
		}
	};

	struct myEqual {
		bool operator () (const Line &l1, const Line &l2) const {
			return (l1.a == l2.a && l1.b == l2.b && l1.c == l2.c);
		}
	};

	struct LineMap{
		int sameCnt;
		unordered_map<Line, int, myHash, myEqual> colinear;

		LineMap(): sameCnt(0) {}

		void add(Line l) {

			if (l.a == 0 && l.b == 0)
				sameCnt++;
			else
				colinear[l]++;
		}

		void show() {
			cerr << "sameCnt = " << sameCnt << endl;
			for (auto &x: colinear)
				cerr << x.first.a << '\t' << x.first.b << '\t' << x.first.c << '\t' << x.second << endl;
		}
	};

	struct myLess {
		bool operator() (const Point &p1, const Point &p2) {
			return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
		}
	};

	struct PointEqual {
		bool operator() (const Point &p1, const Point &p2) {
			return (p1.x == p2.x && p1.y == p2.y);
		}
	};

	public:
	int maxPoints(vector<Point> &points) {
		if (points.size() < 3)
			return points.size();

		sort(points.begin(), points.end(), myLess());

		//vector<Point>::iterator e_it = unique(points.begin(), points.end(), PointEqual());
		vector<Point>::iterator e_it = points.end();

		vector<LineMap> lineMap;

		for (auto i_it = points.begin(); i_it+1 != e_it; i_it++) {
			lineMap.push_back(LineMap());

			for (auto j_it = i_it+1; j_it != e_it; j_it++) {

				lineMap.back().add(Line(j_it->y-i_it->y, i_it->x-j_it->x, i_it->y*(j_it->x-i_it->x)-i_it->x*(j_it->y-i_it->y)));
			}
		}

		//cerr << "lineMap size = " << lineMap.size() << endl;
		//for (auto &x: lineMap)
			//x.show();

		int maxPoints = 0;
		for (auto &x: lineMap) {
			if (x.colinear.empty()) {
				if (maxPoints < 1+x.sameCnt)
					maxPoints = 1+x.sameCnt;
			}
			else
				for (auto &y: x.colinear)
					if (maxPoints < y.second+1+x.sameCnt)
						maxPoints = y.second+1+x.sameCnt;
		}

		return maxPoints;
	}
};

int main() {
	int x, y;
	vector<Point> points;

	while (cin >> x >> y)
		points.push_back(Point(x, y));

	Solution sol;

	cout << sol.maxPoints(points) << endl;

	return 0;
}
