#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

ostream & operator <<(ostream &os, const Point &p) {
	os<<'('<<p.x<<", "<<p.y<<')';
}


class Solution {
	public:
		int maxPoints(vector<Point> &points) {
			int n = points.size(); //number of the points
			if (n<=2){return n;}   
			vector<double> k; //vector to store the slops for one point with all the other points
			int res = 0;

			for (int i=0;i<n;i++){ // for each point in the 2d plane
				k.clear();
				int dup = 1; // number of the duplicates with currrent point
				for (int j=0;j<n;j++){ 
					if (i!=j){ // for every other point
						if (points[i].x-points[j].x==0){ // if the slope is a vertical line
							if (points[i].y-points[j].y==0){ // if the point j is the same as point i
								dup++;  
							}else{
								k.push_back(99999); //store the vertical line to a specific slope
							}
						}else{ // if it is the regular slop between point i and j
							k.push_back(10000*(points[i].y-points[j].y)/(points[i].x-points[j].x)); // store the slope
						}
					}
				}

				sort(k.begin(),k.end()); //sort the slopes for counting

				int pp = 1; //number of points in the same line of the point i
				if (k.size()==0){pp=0;} 

				for (int jj=1;jj<k.size();jj++){ //count pp
					if (k[jj]==k[jj-1]){
						pp++;
					}else{
						if (pp+dup>res){res=pp+dup;} // res = pp + the number of duplicates
						pp = 1;
					}
				}
				if (pp+dup>res){res = pp+dup;}
			}

			return res;
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
