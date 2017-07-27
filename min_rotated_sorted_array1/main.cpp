#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		int findMin(vector<int> &num) {
			return find_min(num, 0, num.size()-1);
		}

		int find_min(vector<int> &num, int lower, int upper) {

			if (lower == upper || num[lower] < num[upper])
				return num[lower];

			int mid = (lower+upper) / 2;

			if (num[lower] == num[upper] && num[mid] == num[upper]) {
				int target1 = find_min(num, lower, mid);
				int target2 = find_min(num, mid+1, upper);
				if (target1 < target2)
					return target1;
				else
					return target2;
			}
			else {
				if (num[mid] >= num[lower] && num[mid] >= num[upper])
					if (mid > lower)
						lower = mid;
					else
						lower ++;
				else
					if (num[mid] <= num[lower] && num[mid] <= num[upper])
						if (upper > mid)
							upper = mid;
						else
							upper -- ;

				return find_min(num, lower, upper);
			}

		}
};

int main()
{
	int n, x, actual_min;
	vector< int > num;

	while(cin >> n) {
		num.resize(n);
		cin>>actual_min;

		//cout<<"reading "<<n<<" integers, min = "<<actual_min<<endl;


		for (int i = 0; i < n; i++) {
			cin>>x;
			num[i] = x;
		}


		Solution s;
		int found_min = s.findMin(num);
		cout<<found_min<<'\t'<<actual_min<<'\t'<<( (found_min == actual_min)?"Pass":"Fail" )<<endl;
		//abort();
	}
	return 0;
}
