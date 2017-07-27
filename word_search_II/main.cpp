#include <iostream>
#include <vector>
#include <string>
#include "dan.h"
#include <unordered_set>

using namespace std;

class Solution {
	public:
		class TrieNode {
			public:
				vector<TrieNode *> children;
				bool terminal;
			public:
				// Initialize your data structure here.
				TrieNode() {
					terminal = false;
					children.resize(26, NULL);
				}
		};


		class Trie {
			public:
				Trie() {
					root = new TrieNode();
				}

				// Inserts a word into the trie.
				void insert(string s) {
					insert(root, s);
				}

				void insert(TrieNode *h, string s) {
					if (s.size()) {
						if (!h->children[s[0] - 'a'])
							h->children[s[0] - 'a'] = new TrieNode();

						insert(h->children[s[0] - 'a'], s.substr(1));
					}
					else
						h->terminal = true;
				}

				// Returns if the word is in the trie.
				bool search(string key) {
					return search(root, key);
				}

				bool search(TrieNode *h, string key) {
					if (!key.size()) {
						if (h->terminal) return true;
						else return false;
					}

					if (!h->children[key[0] - 'a'])
						return false;
					else
						return search(h->children[key[0] - 'a'], key.substr(1));
				}

				// Returns if there is any word in the trie
				// that starts with the given prefix.
				bool startsWith(string prefix) {
					return startsWith(root, prefix);
				}

				bool startsWith(TrieNode *h, string prefix) {
					if (!prefix.size()) return true;

					if (!h->children[prefix[0] - 'a'])
						return false;
					else
						return startsWith(h->children[prefix[0] - 'a'], prefix.substr(1));
				}

			private:
				TrieNode* root;
		};

	public:
		Trie trie;

		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			unordered_set<string> res;

			vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));

			for (auto &x: words) trie.insert(x);

			string word;

			for (int i=0; i<board.size(); i++) {
				for (int j=0; j<board[0].size(); j++) {
					word.push_back(board[i][j]);
					used[i][j] = true;
					bt(word, i, j, board, used, res);
					used[i][j] = false;
					word.pop_back();
				}
			}

			return vector<string>(res.begin(), res.end());
		}

		void bt(string &word, int i, int j, vector<vector<char> > &board, vector<vector<bool> > &used, unordered_set<string> &res) {
			if (trie.search(word)) res.insert(word);

			if (!trie.startsWith(word)) return;


			if (i>0 && !used[i-1][j]) {
				used[i-1][j] = true;
				word.push_back(board[i-1][j]);
				bt(word, i-1, j, board, used, res);
				used[i-1][j] = false;
				word.pop_back();
			}

			if (i+1<board.size() && !used[i+1][j]) {
				used[i+1][j] = true;
				word.push_back(board[i+1][j]);
				bt(word, i+1, j, board, used, res);
				used[i+1][j] = false;
				word.pop_back();
			}

			if (j>0 && !used[i][j-1]) {
				used[i][j-1] = true;
				word.push_back(board[i][j-1]);
				bt(word, i, j-1, board, used, res);
				used[i][j-1] = false;
				word.pop_back();
			}

			if (j+1<board[0].size() && !used[i][j+1]) {
				used[i][j+1] = true;
				word.push_back(board[i][j+1]);
				bt(word, i, j+1, board, used, res);
				used[i][j+1] = false;
				word.pop_back();
			}
		}
};

int main() {
	vector<string> words;
	cin >> words;
	cout << words << endl;

	vector<vector<char> > board;
	cin >> board;
	cout << board << endl;

	Solution sol;
	cout << sol.findWords(board, words) << endl;

	return 0;
}
