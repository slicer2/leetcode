#include <vector>
#include "dan.h"
#include <iostream>
#include <unordered_set>
#include <stack>
#include <list>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		vector<vector<int> > buildGraph(int n, vector<pair<int, int> > pre) {
			vector<vector<int> > G = vector<vector<int> >(n, vector<int>(0));
			vector<unordered_set<int> > dup = vector<unordered_set<int> >(n);

			for (auto &y: pre) {
				if (dup[y.first].find(y.second) == dup[y.first].end()) {
					G[y.first].push_back(y.second);
					dup[y.first].insert(y.second);
				}
			}

			return G;
		}

		bool hasCycle(int start_node, vector<vector<int> > &G, vector<int> &mark) {
			/* first: 0 - normal course id, 1 - course id to be marked to 2
			 * second: course id
			 */
			stack<pair<int, int> > sta;
			sta.push(make_pair(1, start_node));
			sta.push(make_pair(0, start_node));

			while (!sta.empty()) {
				pair<int, int> p = sta.top();
				sta.pop();

				if (p.first == 0) {
					for (auto &y: G[p.second]) {
						if (mark[y] == 1)
							return true;

						if (mark[y] == 0) {
							mark[y] = 1;
							sta.push(make_pair(1, y));
							sta.push(make_pair(0, y));
						}
					}
				}
				else {
					mark[p.second] = 2;
				}
			}

			return false;
		}

		bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
			vector<vector<int> > G = buildGraph(numCourses, prerequisites);

			/* mark definition 
			 * 0 : haven't visited
			 * 1 : visited and now see it again from a descendent
			 * 2: visited and now see it from another ancestor
			 */
			vector<int> mark = vector<int>(numCourses, 0);

			for (int i = 0; i < numCourses; i++) {
				if (mark[i] == 0)
					if (hasCycle(i, G, mark))
						return false;
			}

			return true;
		}
};

int main() {
	int numCourses;
	vector<pair<int, int> > prerequisites;
	int temp1, temp2;

	cin >> numCourses;
	cin.ignore(100, '\n');

	while (cin >> temp1 >> temp2) {
		prerequisites.push_back(make_pair(temp1, temp2));
	}


	Solution sol;
	if (sol.canFinish(numCourses, prerequisites))
		cout << "yes, no cycle, can finish" << endl;
	else
		cout << "no, has cycle, can't finish" << endl;

	return 0;
}
