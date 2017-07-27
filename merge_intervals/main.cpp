#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	class myless {
		public:
			bool operator ()(const Interval &i1, const Interval &i2) {
				return (i1.start < i2.start);
			}
	} mylessobj;

	public:
	vector<Interval> merge(vector<Interval> intervals) {
		if (intervals.size() <= 1)
			return intervals;

		vector<Interval> result;

		sort(intervals.begin(), intervals.end(), mylessobj);

		vector<Interval>::iterator it = intervals.begin(); 

		Interval curr = (*it);

		it++;

		for (; it != intervals.end(); it++) {
			if (it->start <= curr.end) {
				if (it->end > curr.end)
					curr.end = it->end;
			}
			else {
				result.push_back(curr);
				curr = (*it);
			}
		}

		result.push_back(curr);

		return result;
	}
};

ostream & operator << (ostream &os, const Interval &intv) {
	os << "(" << intv.start << ", " << intv.end << ")  ";
	return os;
}

int main() {

	int n1, n2;
	vector<Interval> intervals;

	while (cin >> n1 >> n2) {
		intervals.push_back(Interval(n1, n2));
	}

	Solution sol;
	cout << sol.merge(intervals) << endl;

	return 0;
}
