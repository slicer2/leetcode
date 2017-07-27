#include <iostream>
#include "dan.h"
#include <string>
#include <list>
#include <cassert>

using namespace std;

class Solution {
	void removeSlash(string &path, int &p) {
		while (p != (int)path.length() && path[p] == '/') {
			p++;
		}
	}

	string readDir(string &path, int &p) {
		int start = p;
		while (p < (int)path.length() && path[p] != '/')
			p++;

		return path.substr(start, p-start);
	}

	public:
	string simplifyPath(string path) {
		if (path.length() == 0)
			return path;

		list<string> pathComp;

		int p = 0;

		while (p < (int)path.length()){
			string dir = readDir(path, p);

			if (dir == "..") {
				if (pathComp.size() > 0 && pathComp.back() != "" && pathComp.back() != ".")
					pathComp.pop_back();
			}
			else {
				if (dir != "." || p == 1) {
					pathComp.push_back(dir);
				}
			}


			removeSlash(path, p);

			cerr << "p = " << p << "   " << pathComp << endl;
		}

		string result;

		if (pathComp.size() > 1 && pathComp.front() == ".")
			pathComp.pop_front();

		for (list<string>::iterator it = pathComp.begin(); it != pathComp.end(); it++)
			result = result + (*it) + "/";

		cerr << "before return:" << endl << result << endl;

		if (result.length() > 1)
			return result.substr(0, result.length()-1);
		else
			return result;
	}
};

int main() {
	string s;

	cin >> s;

	Solution sol;

	cout << sol.simplifyPath(s) << endl;

	return 0;
}
