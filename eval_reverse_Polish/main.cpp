//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:

//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		int evalRPN(vector<string> &tokens) {
			vector<string>::iterator it;
			stack<int> operand;

			for (it=tokens.begin(); it != tokens.end(); it++) {
				if (*it == "+") {
					int op2 = operand.top();
					operand.pop();
					int op1 = operand.top();
					operand.pop();
					operand.push(op1 + op2);
				}
				else
					if (*it == "-") {
						int op2 = operand.top();
						operand.pop();
						int op1 = operand.top();
						operand.pop();
						operand.push(op1 - op2);
					}
					else
						if (*it == "*") {
							int op2 = operand.top();
							operand.pop();
							int op1 = operand.top();
							operand.pop();
							operand.push(op1 * op2);
						}
						else
							if (*it == "/") {
								int op2 = operand.top();
								operand.pop();
								int op1 = operand.top();
								operand.pop();
								operand.push(op1 / op2);
							}
							else {
								stringstream ss(*it);
								int n;
								ss>>n;
								operand.push(n);
							}
			}
			return operand.top();
		}
};


int main() {
	string s;
	vector<string> tokens;

	while (cin >> s)
		tokens.push_back(s);

	Solution sol;
	cout<<sol.evalRPN(tokens)<<endl;
}
