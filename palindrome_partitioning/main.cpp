#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

template <typename T>
ostream & operator << (ostream &os, vector<T> &v) {
	typename vector<T>::iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it) << ' ';

	return os;
}

template <typename T>
ostream & operator << (ostream &os, vector<vector<T> > &v) {
	typename vector<vector<T> >::iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it) << endl;

	return os;
}

class Solution {

	vector<vector<int> > rightIdx;

	string s;

	vector<vector<int> > manacher (string s) {
		vector<int> result;
		int tstep;

		int len_result = s.length()*2 + 1;

		result.resize(len_result);

		result[0] = 0;

		int c = 0;

		for (int i=1; i<len_result; i++) {
			if (i > c+result[c]) {
				tstep = 0;
				while (  i-tstep-1 >= 0 && i+tstep+1 < len_result && ( (i+tstep+1) % 2 == 0 || s[(i-tstep-1)/2] == s[(i+tstep+1)/2] ) ) 
					tstep++;

				c = i;

				result[i] = tstep;
			}
			else {
				if (i+result[2*c-i] >= c+result[c]) {
					tstep = c+result[c]-i;
					while (  i-tstep-1 >= 0 && i+tstep+1 < len_result && ( (i+tstep+1) % 2 == 0 || s[(i-tstep-1)/2] == s[(i+tstep+1)/2] ) ) 
						tstep++;

					c = i;

					result[i] = tstep;
				}
				else 
					result[i] = result[2*c-i];
			}

		}


		vector<vector<int> > palindrome;
		palindrome.resize(s.length());

		int actual_len, actual_left, actual_right;

		for (int i=0; i<result.size()-1; i++) {
				if (i % 2)
					actual_len = result[i]/2*2 + 1;
				else
					actual_len = (result[i]+1)/2*2;

				actual_left = (i-result[i])/2;
				actual_right = (i+result[i])/2-1;

				while (actual_len > 0) {
					palindrome[actual_left].push_back(actual_right);
					actual_left++;
					actual_right--;
					actual_len -= 2;
				}
		}

		return palindrome;
	}

	vector<vector<string> > printPartition(int left_edge) {

		vector<vector<string> > rightPartition;

		for (vector<int>::iterator right_it = rightIdx[left_edge].begin(); 
				right_it != rightIdx[left_edge].end(); right_it++) {

			if (*right_it == s.length()-1) {
				vector<string> tmp;
				tmp.push_back(string(s.substr(left_edge, (*right_it)-left_edge+1)));
				rightPartition.push_back(tmp);
			}

			else {
				vector<vector<string> > subRightPartition = printPartition(*right_it+1);

				for (vector<vector<string> >::iterator r_it = subRightPartition.begin(); 
						r_it != subRightPartition.end(); r_it++) {

					r_it->push_back(s.substr(left_edge, (*right_it)-left_edge+1));

					rightPartition.push_back(*r_it);
				}
			}
		}

		return rightPartition;
	}

	public:

	vector<vector<string>> partition(string str) {

		s = str;

		rightIdx = manacher(s);

		vector<vector<string> > rightPartition = printPartition(0);

		for (vector<vector<string> >::iterator p_it = rightPartition.begin();
				p_it != rightPartition.end(); p_it++) {

			vector<string> reverse_sentence(*p_it);

			copy(reverse_sentence.rbegin(), reverse_sentence.rend(), p_it->begin());
		}

		return rightPartition;
	}
};

int main() {
	string s;

	cin >> s;

	Solution sol;

	vector<vector<string> > allPartition = sol.partition(s);

	cout << allPartition;

	return 0;
}
