#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>

#ifndef __DAN_H
#define __dan_H

#define PLINE cerr << "line " << __LINE__ << ":"

template <typename T>
void showStack(std::ostream &os, std::stack<T> &sta) {
	std::stack<T> sta1;

	while (!sta.empty()) {
		os << sta.top() << std::endl;

		sta1.push(sta.top());
		sta.pop();
	}
	
	if (!sta1.empty()) {
		sta.push(sta1.top());
		sta1.pop();
	}
}

template <typename T1, typename T2>
std::ostream & operator << (std::ostream &os, const std::pair<T1, T2> &p) {
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}

template <typename T>
std::ostream & operator << (std::ostream &os, const std::vector<T> &v) {
	typename std::vector<T>::const_iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it) << ' ';

	return os;
}

template <typename T>
std::ostream & operator << (std::ostream &os, const std::unordered_set<T> &v) {
	for (auto &x: v) os << x << ' ';

	return os;
}

template <typename T>
std::ostream & operator << (std::ostream &os, const std::set<T> &v) {
	for (auto &x: v) os << x << ' ';

	return os;
}

template <typename T>
std::ostream & operator << (std::ostream &os, const std::vector<std::vector<T> > &v) {
	typename std::vector<std::vector<T> >::const_iterator it = v.begin();
	for (; it != v.end(); it++)
		os << (*it) << std::endl;

	return os;
}

template <typename T>
std::ostream & operator << (std::ostream &os, const std::list<T> &l) {
	typename std::list<T>::const_iterator it = l.begin();
	for (; it != l.end(); it++)
		os << (*it) << ' ';

	return os;
}

template<typename T>
std::istream & operator >> (std::istream &is, std::vector<T> &v) {
	std::string s;
	getline(is, s);
	T n;

	std::stringstream ss(s);

	while (ss >> n)
		v.push_back(n);

	return is;	
}

template <typename T>
std::istream & operator >> (std::istream & is, std::vector<std::vector<T> > &matrix) {
	std::vector<T> row;

	while (is >> row) {
		matrix.push_back(row);
		row.clear();
	}

	return is;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

TreeNode *constructBinaryTree(std::string &s) {
	std::queue<TreeNode **> nodes;

	std::stringstream ss(s);

	TreeNode *root = NULL;

	std::string val;

	nodes.push(&root);

	while ((ss>> val) && !nodes.empty()) {
		TreeNode **p = nodes.front();
		nodes.pop();

		if (val != "#") {
			*p = new TreeNode(stoi(val));
			nodes.push(&( (*p)->left ));
			nodes.push(&( (*p)->right ));
		}
	}

	return root;
}


std::string serializeBinaryTree(TreeNode *root){
	std::string s, nulls;

	std::queue<TreeNode *> q;

	if (root)
		q.push(root);

	while (!q.empty()) {
		TreeNode *p = q.front();
		q.pop();

		if (p) {
			q.push(p->left);
			q.push(p->right);
			s = s +  nulls + std::to_string(p->val) + " ";
			nulls = "";
		}
		else
			nulls = nulls + "# ";
	}

	if (s[s.length()-1] == ' ') s = s.substr(0, s.length()-1);
	return s;
}

void preorder(TreeNode *root){
	if (!root)
		return;

	std::cout << root->val << " ";

	preorder(root->left);

	preorder(root->right);
}

void inorder(TreeNode *root){
	if (!root)
		return;

	inorder(root->left);

	std::cout << root->val << " ";

	inorder(root->right);
}

#endif 
