#include <iostream>
#include <string>
#include <vector>

using namespace std;

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



// Your Trie object will be instantiated and called as such:

int main() {
	Trie trie;

	trie.insert("hello");

	cout << "hello "; if (trie.search("hello")) cout << "yes" << endl;
	cout << "hell "; if (trie.search("hell")) cout << "yes" << endl;
	cout << "helloo "; if (trie.search("helloo")) cout << "yes" << endl;
	cout << "hell "; if (trie.startsWith("hell")) cout << "yes" << endl;
}
