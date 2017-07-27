#include <iostream>
#include <string>

using namespace std;

class Solution {

		int filterws(string str, int p) {
			while (str[p] == ' ' || str[p] == '\t') {
				p--;

				if (p < 0) break;
			}

			return p;
		}

		int filternws(string str, int p) {
			while (str[p] != ' ' && str[p] != '\t') {
				p--;

				if (p < 0) break;
			}

			return p;
		}
		
	public:
		void reverseWords(string &s) {
			string ts;

			if (s.size() == 0) return;

			int pos = s.size()-1, end_pos;
			pos = filterws(s, pos);

			if (pos == -1) {
				s = ts;
				return;
			}

			while(pos > -1){
				end_pos = filternws(s, pos);
				ts += s.substr(end_pos+1, pos-end_pos);

				pos = end_pos;
				//cout<<pos<<" ";

				end_pos = filterws(s, pos);
				if (end_pos > -1)
					ts += " ";
				else
					break;

				pos = end_pos;
			}

			//cout<<endl;

			s = ts;
		}
};

int main(){
	string s;
	Solution sol;

	while(getline(cin, s)) {
		cout<<"->"<<s<<"->"<<endl;
		sol.reverseWords(s);
		cout<<"<-"<<s<<"<-"<<endl;

		s.clear();
	}
	return 0;
}
