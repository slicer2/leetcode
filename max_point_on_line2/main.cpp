#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

//ostream & operator <<(ostream &os, const Point &p) {
//	os<<'('<<p.x<<", "<<p.y<<')';
//}


class Solution {

	struct Init2Zero{
		int val;
		Init2Zero(int n=0):val(n) {};
		void operator ++(int) {
			val++;
		}
	};

	struct Less {
		bool operator ()(const Point &p1, const Point &p2){
			return (p1.y*p2.x - p1.x*p2.y < 0);
		}
	};

	int gcd(int a, int b) {
		if (!a)
			return b;
		else
			if (b % a == 0)
				return a;
			else
				return gcd(b % a, a);
	}

	public:


	typedef map<Point, Init2Zero, Less > groupBySlope;

	int maxPoints(vector<Point> &points) {
		int maxPoints = 0;

		groupBySlope groupBySlopeCurrPoint;

		for (int i=0; i<points.size()-1; i++) {

			groupBySlopeCurrPoint.clear();

			//cout<<"current point "<<points[i]<<endl;

			for (int j=i+1; j<points.size(); j++) {

				Point dirVec(points[i].y-points[j].y, points[j].x - points[i].x);
				int g = gcd(abs(dirVec.x), abs(dirVec.y));
				dirVec.x /= g;
				dirVec.y /= g;
				if (dirVec.x < 0) {
					dirVec.x = -dirVec.x;
					dirVec.y = -dirVec.y;
				}
				else
					if (dirVec.x == 0 && dirVec.y < 0)
						dirVec.y = -dirVec.y;

				groupBySlopeCurrPoint[dirVec]++;
				if (maxPoints < groupBySlopeCurrPoint[dirVec].val)
					maxPoints = groupBySlopeCurrPoint[dirVec].val;

				//cout<<"check "<<points[j]<<", dir vector "<<dirVec<<", total "<<groupBySlopeCurrPoint[dirVec].val<<endl;
			}
		}

		return maxPoints+1;
	}
};



int main()
{
	int n;
	int x, y;
	vector<Point> p;

	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x>>y;
		p.push_back(Point(x, y));
	}

	Solution s;
	cout<<"max number of points on a line = "<<s.maxPoints(p)<<endl;
	return 0;
}
