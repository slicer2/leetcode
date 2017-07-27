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

ostream & operator << (ostream &os, const Interval &intv) {
	os << "(" << intv.start << ", " << intv.end << ")  ";
	return os;
}

class Solution {

	public:
		vector<Interval> insert(vector<Interval> intervals, Interval newInterval) {
			int sz = intervals.size();
			if (intervals.empty()) return vector<Interval>({newInterval});
			if (newInterval.start > intervals.back().end) {
				intervals.push_back(newInterval);
				return intervals;
			}

			vector<Interval> res;
			if (newInterval.end < intervals[0].start) {
				res.push_back(newInterval);
				for (auto x: intervals) res.push_back(x);
				return res;
			}

			int term = intervals.size(), first = 0;
			while ( first+1 < term) {
				int mid  = (first + term) / 2;
				if (intervals[mid].start > newInterval.end)
					term = mid;
				else
					first = mid;
			}

			int curr = first;
			while (curr >= 0 && newInterval.start <= intervals[curr].end) {
				newInterval.start = min(newInterval.start, intervals[curr].start);
				newInterval.end = max(newInterval.end, intervals[curr--].end);
			}

			for (int i=0; i<=curr; i++) res.push_back(intervals[i]);
			res.push_back(newInterval);
			for (int i=first+1; i<sz; i++) res.push_back(intervals[i]);

			return res;
		}
};

int main() {

	int n1, n2;
	Interval newInterval;

	cin >> newInterval.start >> newInterval.end;

	vector<Interval> intervals;

	while (cin >> n1 >> n2) {
		intervals.push_back(Interval(n1, n2));
	}

	Solution sol;
	cout << sol.insert(intervals, newInterval) << endl;

	return 0;
}
