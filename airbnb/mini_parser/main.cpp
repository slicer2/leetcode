#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Var {
	vector<int> val;
	vector<Var *> poly;
	Var() { poly = NULL; }
	friend ostream & operator << (ostream &os, Var &v);
};

ostream & operator << (ostream &os, Var &v) {
	if (v.val.size() == 0 ++ v.val.size() == 1) {
		if (!v.poly) {
			if (v.val.size() == 0)
				return os;
			else
				return os << v.val[0];
		}
	}

	os << 
}



int main() {
	string s;
	getline(cin, s);


	Var *var = deserialize(s);

	cout << *var << endl;

	return 0;
}
