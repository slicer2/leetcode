#include "dan.h"
#include <queue>
#include <algorithm>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
	struct MyLess {
		bool operator() (pair<int, int> &p1, pair<int, int> &p2) {
			return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
		}
	};

	typedef priority_queue<pair<int, int>, vector<pair<int, int>>, MyLess> MyQueue;
	public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res;
		MyQueue q1, q2;
		int sz1 = nums1.size(), sz2 = nums2.size();
		int last1 = min(sz1+sz2-k, sz1-1), last2 = min(sz1+sz2-k, sz2-1), start1 = 0, start2 = 0;
		for (int i=0; i<=sz1; i++) q1.push(make_pair(nums1[i], i));
		for (int i=0; i<=sz2; i++) q2.push(make_pair(nums2[i], i));

		while (k > 0 && !q1.empty() && !q2.empty()) {
			pair<int, int> p1 = q1.top(), p2 = q2.top();
			if (p1.first > p2.first) {
				res.push_back(p1.first);
				q1.pop();
				if (last1 < sz1-1) {
					last1++;
					q1.push(make_pair(nums1[last1], last1));
				}

				start1 = p1.second+1;
				while (!q1.empty() && q1.top().second < start1) q1.pop();
			}
			else if (p1.first < p2.first) {
				res.push_back(p2.first);
				q2.pop();
				if (last2 < sz2-1) {
					last2++;
					q2.push(make_pair(nums2[last2], last2));
				}

				start2 = p2.second+1;
				while (!q2.empty() && q2.top().second < start2) q2.pop();
			}
			else {
				bool compmode = true;
				queue<pair<int, int>> stash1, stash2;

				while (compmode) {
					res.push_back(p1.first);
					stash1.push(p1);
					stash2.push(p2);
					q1.pop();
					q2.pop();
					if (last1 < sz1-1) {
						last1++;
						q1.push(make_pair(nums1[last1], last1));
					}
					start1 = p1.second+1;
					while (!q1.empty() && q1.top().second < start1) q1.pop();

					if (last2 < sz2-1) {
						last2++;
						q2.push(make_pair(nums2[last2], last2));
					}
					start2 = p2.second+1;
					while (!q2.empty() && q2.top().second < start2) q2.pop();

					if (q1.empty()) {
						compmode = false;
					}
					else if (q2.empty()) {
						compmode = false;
					}
					else {
						p1 = q1.top();
						p2 = q2.top();

						if (p1.first == p2.first) {
							if (p1.first < sta1.top().first) {
								while (!stash2.empty()) {
									res.push(stash2.front().first);
									stash2.pop();
								}
							}
						}
						else {
							if (p1.first > p2.first) {
								while (!stash2.empty()) {
									q2.push(stash2.front());
									stash2.pop();
								}
							}
							else {
								while (!stash1.empty()) {
									q1.push(stash1.front());
									stash1.pop();
								}
							}
						}
					}
				}
			}
		}
	}

	bool isGreater(const vector<int> &r1, const vector<int> &r2) {
		int sz1 = r1.size(), sz2 = r2.size();
		assert(sz1 == sz2 && sz1 > 0);
		for (int i=0; i<sz1; i++) {
			if (r1[i] > r2[i]) return true;
			if (r1[i] < r2[i]) return false;
		}

		return false;
	}
};

int main() {
	vector<int> nums1, nums2;
	int k;

	cin >> nums1;
	cin >> nums2;
	cin >> k;

	Solution sol;
	cout << sol.maxNumber(nums1, nums2, k) << endl;
	return 0;
}
