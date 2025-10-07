#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>

class Node {
public:
	bool isWord;
	std::unordered_map<char,Node* > children;
	Node() {
		isWord = false;
		children=std::unordered_map<char,Node* >();
	}
};

class Tree {
	Node *root;
	Node* addWordImpl(Node *root,std::string word) {
		Node *node=root==nullptr?new Node():root;
		const int len=word.length();
		if (len==0){
			node->isWord=true;
		}else{
			const char c=word[0];
			Node *child=node->children[c];
			const std::string substr=word.substr(1,len-1);
			node->children[word[0]]=this->addWordImpl(child,substr);
		}
		return node;
	}
	void removeWordImpl(Node *root,std::string word) {
		if (root==nullptr)return;
		if (word.length()==0){
			root->isWord=false;
			return;
		}
		const int len=word.length();
		const char c=word[0];
		Node *child=root->children[c];
		const std::string substr=word.substr(1,len-1);
		return removeWordImpl(child,substr);
	}
	bool containsWordImpl(Node *root,std::string word) {
		if (root==nullptr)return false;
		if (root->isWord&&word.length()==0)return true;
		if (word.length()==0)return false;
		const char c=word[0];
		const int len=word.length();
		Node *child=root->children[c];
		const std::string substr=word.substr(1,len-1);
		return containsWordImpl(child,substr);
	}
public:
	Tree(){
		this->root=nullptr;
	}
	void addWord(std::string word) {
		root = this->addWordImpl(this->root,word);
	}
	void removeWord(std::string word){
		removeWordImpl(this->root,word);
	}
	bool containsWord(std::string word){
		return this->containsWordImpl(this->root,word);
	}
	~Tree(){

	}
};

int main() {
	Tree t=Tree();
	const std::vector<std::string> addWords = {
		"hello",
		"halo",
		"helo",
		"alo",
		"alee",
		"",
	};

	const std::vector<std::string> removeWords = {
		"halo",
		"helo",
		"hhelo",
		"alee",
	};

	for (const std::string &word : addWords){
		t.addWord(word);
	}
	for (const std::string &word : removeWords){
		t.removeWord(word);
	}
	for (const std::string &word : addWords){
		std::cout<<"contains "<<word<<": "<<t.containsWord(word)<<"\n";
	}
	return 0;
}
