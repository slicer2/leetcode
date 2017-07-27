#include <iostream>
#include <string>
#include <vector>
#include "dan.h"
#include <algorithm>

using namespace std;

class Solution {
    vector<int> alph;

    public:
        void prep(const string &s) {
            alph.resize(s.size()+1, 0);
            int p = 0, sz = s.size();

            for (int q=1; q<sz; q++) {
                while (p>0 && s[q] != s[p])
                    p = alph[p];

                if (s[q] == s[p])
                    alph[q+1] = ++p;
            }
        }

        string shortestPalindrome(string s) {
            prep(s);

            int p = 0, q = 0, sz = s.size();

            while (q+p < sz) {
                while (p>0 && s[sz-q-1] != s[p])
                    p = alph[p];

                if (s[sz-q-1] == s[p]) p++;

				q++;
            }

            string t = s.substr(sz-q+p);
            reverse(t.begin(), t.end());
            return t+s;
        }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.shortestPalindrome(s) << endl;
    return 0;
}
