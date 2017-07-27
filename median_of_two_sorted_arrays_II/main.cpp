#include <iostream>
#include <cassert>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			//for (int i=0; i<m; i++)
			//	cout << A[i] << ' ';
			//cout << endl;


			//for (int i=0; i<n; i++)
			//	cout << B[i] << ' ';
			//cout << endl;

			int start_A, start_B, len_A = m, len_B = n, mid_A, mid_B;
			int result_idx;
			double result;
			int nToRight, nToLeft;
			int cutRightA = 0, cutRightB = 0, cutLeftA = 0, cutLeftB = 0;
			int half_len = (m+n-1)/2;


			start_A = cutLeftA;
			start_B = cutLeftB;

			len_A = m - cutLeftA - cutRightA;
			len_B = n - cutLeftB - cutRightB;

			//cerr << "total_len = " << m+n << '\t' << "to left/right = " << half_len << endl;

			//cerr << "s_A" << '\t' << "l_A" << '\t' << "m_A" << '\t' << "mAVal" << '\t' << "cLA" << '\t' << "cRA" << '\t' << "s_B" << '\t' << "l_B" << '\t' << "m_B" << '\t' << "mBVal" << '\t' << "cLB" << '\t' << "cRB" << '\t' << "toL" << '\t' << "toR" << endl;

			/**
			 * cutLeftA and cutRightA specify the number of elements of the left/right of A
			 * that cannot possibly contain the median (m+n odd) or touch the median interval
			 * (m+n even). 
			 * startA, len_A then represent the remaining possibility
			 * half_len represents the number of elements to the left/right of median (m+n odd)
			 * or the number of elements to the left/right of median interval (m+n even)
			 *
			 * when m+n odd, each iteration will cut len_A or len_B in half until either 
			 * len_A or len_B becomes zero
			 *
			 * when m+n even, each iteration will cut len_A or len_B in half until either
			 *  1. len_A == 2, len_B == 1, A[start_A+1] >= B[start_B], cutRightA+cutRightB == half_len
			 *  2. len_A == 1, len_B == 1, B[start_B+1] >= A[start_A], cutRightA+cutRightB == half_len
			 *  3. len_A == 1, len_B == 1
			 * case 3 is straightforward
			 # case 1 and 2 need a little adjustment at the end of iteration to make len_A reduce from 2
			 * to 1 (or len_B reduce from 2 to 1), then we come to case 3
			 **/
			while (!( (m+n) % 2 == 0 && len_A == 1 && len_B == 1 ) && len_A != 0 && len_B != 0) {
				mid_A = start_A + len_A/2;
				mid_B = start_B + len_B/2;


				nToRight = m - (mid_A+1) + n - (mid_B+1);
				nToLeft = mid_A + mid_B;

				if (A[mid_A] > B[mid_B]) {
					if (nToRight < half_len)
						cutRightA = m - mid_A;
					else
						if (nToRight == half_len)
							cutRightA = m - (mid_A + 1);

					if (nToLeft < half_len)
						cutLeftB = mid_B+1;
					else
						if (nToLeft == half_len)
							cutLeftB = mid_B;
				}
				else {
					if (nToRight < half_len)
						cutRightB = n - mid_B;
					else
						if (nToRight == half_len)
							cutRightB = n - (mid_B+1);

					if (nToLeft < half_len)
						cutLeftA = mid_A+1;
					else
						if (nToLeft == half_len)
							cutLeftA = mid_A;
				}

				start_A = cutLeftA;
				start_B = cutLeftB;

				len_A = m - cutLeftA - cutRightA;
				len_B = n - cutLeftB - cutRightB;

				if ((m+n) % 2 == 0) {
					if (len_A == 2 && len_B == 1 && A[start_A+1] >= B[start_B] && cutRightA+cutRightB == half_len) {
						if (A[start_A] <= B[start_B]) {
							cutLeftA++;
							start_A++;
							len_A = 1;
						}
						else {
							cutLeftB++;
							len_B = 0;
						}
					}

					if (len_B == 2 && len_A == 1 && B[start_B+1] >= A[start_A] && cutRightA+cutRightB == half_len) {
						if (B[start_B] <= A[start_A]) {
							cutLeftB++;
							start_B++;
							len_B = 1;
						}
						else {
							cutLeftA++;
							len_A = 0;
						}
					}
				}

				//cerr << start_A << '\t' << len_A << '\t' << mid_A << '\t' << A[mid_A] << '\t' << cutLeftA << '\t' << cutRightA << '\t' << start_B << '\t' << len_B << '\t' << mid_B << '\t' << B[mid_B] << '\t' << cutLeftB << '\t' << cutRightB << '\t' << nToLeft << '\t' << nToRight << endl;
			}

			len_A = m - cutLeftA - cutRightA;
			len_B = n - cutLeftB - cutRightB;

			if ((m+n) % 2 == 0) {
				if (len_A == 0) {
					result_idx = half_len - cutLeftA;
					result = (B[result_idx]+B[result_idx+1])/2.0;
				}
				else
				if (len_B == 0) {
					result_idx = half_len - cutLeftB;
					result = (A[result_idx]+A[result_idx+1])/2.0;
				}
				else
					result = (A[start_A]+B[start_B])/2.0;
			}
			else {
				if (len_A == 0) {
					result_idx = half_len - cutLeftA;
					result = B[result_idx];
				}
				else
					if (len_B == 0) {
						result_idx = half_len - cutLeftB;
						result = A[result_idx];
					}
					else
						assert(false);
			}

			return result;
		}
};


int main() {
	int m, n;

	const int vrange = 20;
	const int lrange = 7;

	for (int j=0; j<1000; j++) {
		m = rand() % lrange;
		n = rand() % lrange;

		if (m == 0 && n == 0)
			continue;

		int *A = new int [m];
		int *B = new int [n];

		for (int i=0; i<m; i++) {
			A[i] = rand() % vrange;
		}

		sort(A, A+m);

		for (int i=0; i<m; i++)
			cout << A[i] << ' ';
		cout << endl;

		for (int i=0; i<n; i++) {
			B[i] = rand() % vrange;
		}

		sort(B, B+n);

		for (int i=0; i<n; i++)
			cout << B[i] << ' ';
		cout << endl;

		int *C = new int[m+n];
		copy(A, A+m, C);
		copy(B, B+n, C+m);
		sort(C, C+m+n);

		for (int i=0; i<m+n; i++)
			cout << C[i] << ' ';

		cout << endl;

		Solution sol;

		double median = sol.findMedianSortedArrays(A, m, B, n);

		double real_median = (((m+n)%2)?C[(m+n)/2]:(C[(m+n)/2-1]+C[(m+n)/2])/2.0);
		cout << median << ' ' << real_median << endl;

		if (abs(median - real_median) > 0.1) {
			cout << "wrong" << endl;
			break;
		}

		cout << "-------------------------" << endl;

	}

	return 0;
}
//int main() {
//
//	int m, n;
//	int *A, *B;
//
//	cin >> m;
//
//	A = new int [m];
//
//	for (int i=0; i<m; i++)
//		cin >> A[i];
//
//	cin >> n;
//
//	B = new int [n];
//
//	for (int i=0; i<n; i++)
//		cin >> B[i];
//
//	Solution sol;
//
//	cout << sol.findMedianSortedArrays(A, m, B, n) << endl;
//
//	return 0;
//}
