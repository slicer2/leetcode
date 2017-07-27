#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		int minimumTotal(vector<vector<int> > &triangle) {
			vector<int> partial_result(triangle.back());

			for (vector<vector<int> >::reverse_iterator r_it = triangle.rbegin();
				r_it != triangle.rend(); r_it++) {
					if (r_it == triangle.rbegin())
						continue;

					for (int i=0; i<(int)r_it->size(); i++)
						if (partial_result[i] > partial_result[i+1])
							partial_result[i] = partial_result[i+1] + (*r_it)[i]; 
						else
							partial_result[i] = partial_result[i] + (*r_it)[i];
			}

			return partial_result[0];
		}
};

int main() {
	string s;
	int n;
	vector<vector<int> >triangle;

	while (getline(cin, s)) {
		vector<int> partial_triangle;

		stringstream ss(s);
		while (ss >> n)
			partial_triangle.push_back(n);

		triangle.push_back(partial_triangle);
	}

	Solution sol;
	cout << sol.minimumTotal(triangle) << endl;

	return 0;
}
