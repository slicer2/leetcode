#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	private:
		vector<int> kmp(string &needle) {
			int target = needle.size();
			vector<int> pi(target+1, 0);
			int q = 0;
			for (int p=2; p<=target; p++) {
				while (q > 0 && needle[p-1] != needle[q])
					q = pi[q];

				if (needle[p-1] == needle[q]) q++;

				pi[p] = q;
			}

			return pi;
		}

	public:
		int strStr(string haystack, string needle) {
			vector<int> pi = kmp(needle);
			int q = 0, sz = haystack.size(), target = needle.size();
			if (target == 0) return 0;

			for (int p = 0; p < sz; p++) {
				while (q > 0 && haystack[p] != needle[q])
					q = pi[q];

				if (haystack[p] == needle[q]) q++;

				if (q == target) return p-target+1; 
			}

			return -1;
		}
};

int main() {
	char haystack[100], needle[100];
	
	cin >> haystack >> needle;

	Solution sol;
	cout << sol.strStr(haystack, needle) << endl;

	return 0;
}
