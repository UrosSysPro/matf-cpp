#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class PrefixTree;
class Node;

struct Node {
    bool isWord{};
    unordered_map<char, Node*> children;
    static Node* empty() {
        auto node = new Node();
        node->isWord = false;
        node->children = unordered_map<char, Node*>();
        return node;
    }
};

class PrefixTree {
private:
    Node *root = Node::empty();
    Node* addR(Node* node, string word) {
        if (node == nullptr) node = new Node();

        if (word.empty()) {
            node->isWord = true;
        }else {
            node->children[word[0]] = addR(node->children[word[0]], word.substr(1));
        }
        return node;
    }

    void removeR(Node* node, string word) {
        if (node == nullptr) return;

        if (word.empty()) {
            node->isWord = false;
        }else {
            removeR(node->children[word[0]], word.substr(1));
        }
    }

    bool hasR(Node* node, const string& word) {
        if (node == nullptr) return false;

        if (word.empty() && node->isWord) return true;

        if (word.empty()) return false;

        return hasR(node->children[word[0]], word.substr(1));
    }
    void printR(Node* node, const string& prefix) {

    }
    bool deleteR(Node* root) {
        for (auto& [key, value]: root->children) {
            deleteR(value);
        }
        delete root;
    }
public:
    PrefixTree() {}
    ~PrefixTree() { deleteR(root); }
    void add(string value){ root = addR(root, value); }
    void remove(string value){ removeR(root, value); }
    bool has(string value){ return hasR(root, value); }
    void print(){}

};

int main(int argc, char *argv[]) {
    PrefixTree tree = PrefixTree();

    vector<string> addedWords = vector<string>();
    vector<string> removedWords = vector<string>();
    vector<string> testWords = vector<string>();

    addedWords.push_back("hello");
    addedWords.push_back("hello world");
    addedWords.push_back("hello hello");
    addedWords.push_back("hello2");

    removedWords.push_back("hello");
    removedWords.push_back("hello hello");

    testWords.push_back("hello");
    testWords.push_back("hello world");
    testWords.push_back("hello hello");
    testWords.push_back("hello2");

    for (auto& word : addedWords) {
        tree.add(word);
    }

    for (auto& word : removedWords) {
        tree.remove(word);
    }

    for (auto& word : testWords) {
        bool contains = tree.has(word);
        cout << "contains " << word << " " << contains << endl;
    }

    return 0;
}
