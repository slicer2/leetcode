/**
 * If duplicates are allowed in the sorted but rotated array
 * determining if a particular value is present in the array
 * has a complexity of O(n). In the worst case, when the whole
 * array is 1 but one element, which is 2, searching for 2 
 * amounts to scanning through the entire array because 2 can
 * be anywhere among a string of 1's
 */

#include <iostream>
#include <string>

using namespace std;

string ind("");

class Solution {
	int bisection(int A[], int start, int end, int target) {

		//cerr << ind << "bisection: start = " << start << "  end = " << end << endl;

		if (start == end)
			return -1;

		if (start+1 == end) {
			if (A[start] == target)
				return start;
			else
				return -1;
		}

		int mid = (start+end)/2;

		if (A[mid] <= target)
			return bisection(A, mid, end, target);
		else
			return bisection(A, start, mid, target);
	}

	int search_func(int A[], int start, int end, int target){

		//ind += "  ";

		//cerr << ind << "search_func: start = " << start << "  end = " << end << "  target = " << target << endl;

		if (start == end) {
			//ind = ind.substr(0, ind.length()-2);
			return -1;
		}

		if (start + 1 == end) {
			if (A[start] == target) {

				//ind = ind.substr(0, ind.length()-2);
				return start;
			}
			else {
				//ind = ind.substr(0, ind.length()-2);
				return -1;
			}
		}

		int mid = (start+end)/2;


		if (A[start] < A[end-1]) {
			//ind = ind.substr(0, ind.length()-2);
			return bisection(A, start, end, target);
		}
		else {
			if (A[mid] > A[start]) {// mid on the left segment
				if (target <= A[mid] && target >= A[start]) {
					//ind = ind.substr(0, ind.length()-2);
					return bisection(A, start, mid+1, target);
				}
				else {
					//ind = ind.substr(0, ind.length()-2);
					return search_func(A, mid+1, end, target);
				}
			}
			else { // mid on the right segment
				if (target >= A[mid] && target <= A[end-1]) {
					//ind = ind.substr(0, ind.length()-2);
					return bisection(A, mid, end, target);
				}
				else {
					//ind = ind.substr(0, ind.length()-2);
					return search_func(A, start, mid, target);
				}
			}
		}
	}

	public:
	int search(int A[], int n, int target) {
		if (n == 0)
			return -1;

		return search_func(A, 0, n, target);
	}
};

int main() {
	int target;

	cin >> target;

	int num, n = 0;
	int *A = new int [1000];

	while (cin >> num)
		A[n++] = num;

	cout << "n = " << n << endl;

	Solution sol;

	int index = sol.search(A, n, target);

	cout << index << "  " << ((index == -1)?-1:A[index]) << endl;

	return 0;
}
