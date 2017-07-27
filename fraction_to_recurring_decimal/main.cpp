#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <utility>
#include <limits>

using namespace std;

class Solution {
	int abs(int x) {
		if (x < 0)
			x = -x;

		return x;
	}


	int div10(int a, int b) {
		int nmin = numeric_limits<int>::min();
		//int debug_ret = 10*a/b;

		if (a < nmin/10) {
			int sum = a;
			int q = 0;

			for (int i=0; i<9; i++) {
				while (sum <= b-a) {
					sum = sum - b;
					q = q + 1;
				}

				sum += a;
			}

			//if (q != debug_ret) {
			//	cerr << "div 10: a = " << a << "  b = " << b << "  debug = " << debug_ret << "  q = " << q << endl;
			//	exit(1);
			//}
			return q;
		}
		else
			return (10*a) / b;
	}

	int mod10(int a, int b) {
		int nmin = numeric_limits<int>::min();
		int ret;
		//int debug_ret = (10*a) % b;

		if (a < nmin/10) {
			int a2, a4, a8;

			if (a < b-a)
				a2 = ((a-b) + a) % b;
			else
				a2 = (2*a) % b;

			if (a2 < b-a2)
				a4 = ((a2-b) + a2) % b;
			else
				a4 = (2*a2) % b;

			if (a4 < b-a4)
				a8 = ((a4-b) + a4) % b;
			else
				a8 = (2*a4) % b;

			if (a2 < b - a8)
				ret = ((a2-b) + a8) % b;
			else
				ret = (a2+a8) % b;
		}
		else 
			ret = (10*a) % b;

		//if (ret != debug_ret) {
		//	cerr << "mod 10: a = " << a << "  b = " << b << "  debug = " << debug_ret << "  ret = " << ret << endl;
		//	exit(1);
		//}

		return ret;
	}

	public:
		string fractionToDecimal(int numerator, int denominator) {
			map<int, int> frac;
			string s;

			if (numerator == numeric_limits<int>::min()) {
				if (denominator == -1)
					return to_string(abs(numeric_limits<int>::min()/10))+to_string(abs(numeric_limits<int>::min() % 10));
				else
					if (denominator == 1)
						return "-"+to_string(abs(numeric_limits<int>::min()/10))+to_string(abs(numeric_limits<int>::min() % 10));
			}

			if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
				s += "-";

			if (numerator > 0)
				numerator = -numerator;

			if (denominator > 0)
				denominator = -denominator;

			int Num = numerator;
			int Quot = Num / denominator;
			Num %= denominator;

			s += to_string(Quot);

			if (Num == 0)
				return s;

			s += ".";

			Quot = div10(Num, denominator);

			size_t pos = s.length();

			while (Num != 0 && frac.find(Num) == frac.end()) {
				//cerr << " Num = " << Num << "   Quot = " << Quot << endl;
				if (Quot < 0)
					exit(1);

				s += to_string(Quot);
				frac.insert(make_pair(Num, pos++));

				Num = mod10(Num, denominator);
				Quot = div10(Num, denominator);
			}

			if (Num == 0)
				return s;
			else
				return s.substr(0, frac[Num])+"("+s.substr(frac[Num], string::npos)+")";
		}
};

int main() {
	int a, b;
	cin >> a >> b;

	Solution sol;
	cout << sol.fractionToDecimal(a, b) << endl;

	return 0;
}
