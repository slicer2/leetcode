#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
	int nextRev(string &version, size_t &start) {
		if (start >= version.length())
			return -1;

		size_t end;

		int ret = stoi(version.substr(start, string::npos), &end);

		start += end+1;

		return ret;
	}

	public:
	int compareVersion(string version1, string version2) {
		size_t start1 = 0, start2 = 0;

		while (true) {
			int rev1 = nextRev(version1, start1);
			int rev2 = nextRev(version2, start2);

			if (rev1 < 0) {
				if (rev2 < 0)
					return 0;
				else {
					if (rev2 > 0)
						return -1;
				}
			}
			else {
				if (rev1 == 0) {
					if (rev2 > 0)
						return -1;
				}
				else {
					if (rev2 < 0)
						return 1;
					else {
						if (rev1 < rev2)
							return -1;

						if (rev1 > rev2)
							return 1;
					}
				}
			}
		}
	}
};

int main() {
	string version1, version2;

	cin >> version1 >> version2;

	cout << version1 << endl << version2 << endl;

	Solution sol;

	cout << sol.compareVersion(version1, version2) << endl;

	return 0;
}
