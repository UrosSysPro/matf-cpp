#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class PrefixTree;

class PrefixTree {
public:
    PrefixTree() {}
    ~PrefixTree() {}
    void add(string value){}
    void remove(string value){}
    bool has(string value){ return false; }
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

    addedWords.push_back("hello");
    addedWords.push_back("hello world");
    addedWords.push_back("hello hello");
    addedWords.push_back("hello2");

    cout<<"contai";

    return 0;
}
