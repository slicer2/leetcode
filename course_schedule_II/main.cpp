#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	public:
		bool dfs(int thisnode, vector<vector<int> > &g, vector<int> &visited, vector<int> &res) {

			if (visited[thisnode] == 0) {
				visited[thisnode] = 1;
				for (auto &y: g[thisnode])
					if (!dfs(y, g, visited, res))
						return false;

				res.push_back(thisnode);
				visited[thisnode] = 2;

				return true;
			}
			else if (visited[thisnode] == 1)
				return false;

			return true;
		}

		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<int> res;

			if (numCourses == 0) return res;

			vector<vector<int> > g(numCourses);
			for (auto &x: prerequisites)
				g[x.first].push_back(x.second);

			vector<int> visited(numCourses, 0);

			for (int i=0; i<numCourses; i++)
				if (!dfs(i, g, visited, res))
					return vector<int>();

			return res;
		}
};

int main() {
	int n;
	cin >> n;


	vector<pair<int, int> > prerequisites;

	int c, p;
	while (cin >> c >> p)
		prerequisites.push_back(make_pair(c, p));

	Solution sol;

	cout << sol.findOrder(n, prerequisites) << endl;
	return 0;
}
