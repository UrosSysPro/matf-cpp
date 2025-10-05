#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

class Node;
class Tree;

class Tree {
private:
	Node *root;
	Node* addWordImpl() {
		return nullptr;
	}
	Node* removeWordImpl() {
		return nullptr;
	}
	Node* containsWordImpl() {
		return nullptr;
	}
public:
	Tree(){}
	void addWord(std::string word) {
		root = addWordImpl();
	}
	void removeWord(std::string word){}
	void containsWord(std::string word){}
	~Tree(){}
};

class Node {
public:
	bool isWord;
	std::unordered_map<char,Node> children;
	Node() {
		isWord = false;
		children=std::unordered_map<char,Node>();
	}
};

int main() {
	Tree t=Tree();

    return 0;
}
