#include <iostream>
#include <stack>
#include "dan.h"

using namespace std;

class MinStack {
	stack<int> sta;
	stack<int> msta;


	public:

	void push(int x) {
		if (msta.empty() || x <= msta.top())
			msta.push(x);

		sta.push(x);
	}

	void pop() {
		if (sta.top() == msta.top())
			msta.pop();

		sta.pop();
	}

	int top() {
		return sta.top();
	}

	int getMin() {
		return msta.top();
	}
};

int main() {
	int num;
	int n = 0;
	MinStack minStack;

	while (cin >> num) {
		minStack.push(num);
		cerr << "push " << '\t' << num << '\t' << "min " << minStack.getMin() << endl;
		n++;
	}

	cerr << "start popping:" << endl;
	while (n>0) {
		cerr << "pop " << minStack.top() << '\t' << "min " << minStack.getMin() << endl;
		minStack.pop();
		n--;
	}

	return 0;
}
