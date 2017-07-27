#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

using namespace std;

void display(unsigned int *t, int n)
{
	for (int i=0; i< n; i++)
		cout << t[i] << ' ';

	cout << endl;
}

class Solution {
	int wid;
	int get_base3_w() {
		return ceil(log(UINT_MAX)/log(3));
	}

	unsigned int *to_base3(unsigned int num) {
		unsigned int *res = new unsigned int[wid];

		for (int i=wid-1; i>=0; i--) {
			res[i] = num % 3;
			num /= 3;
		}

		return res;
	}

	unsigned int to_base10(unsigned int *t) {
		unsigned int result = 0;

		for (unsigned int j=0; j<wid; j++)
			result = result * 3 + t[j];

		return result;
	}

	public:
		int singleNumber(int A[], int n) {
			wid = get_base3_w();
			unsigned int *result = new unsigned int[wid];

			for (int i=0; i<wid; i++)
				result[i] = 0;

			for (int i=0; i<n; i++) {
				unsigned int *t = to_base3((unsigned int)A[i]);

				//cout << "A[" << i << "]:" << endl;
				//display(t, wid);

				for (int j=0; j<wid; j++)
					result[j] = (result[j] + t[j]) % 3;
				//cout << "result:" << endl;
				//display(result, wid);
			}


			return (int)to_base10(result);
		}
};


int main() {
	int n;

	cin >> n;

	int *a = new int[n];

	int num;

	for (int i=0; i<n; i++)
		cin >> a[i];

	Solution s;

	cout << s.singleNumber(a, n) << endl;
}
