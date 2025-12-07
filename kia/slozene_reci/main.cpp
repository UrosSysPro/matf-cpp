#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

class Node{
public:
    bool end_node = false;
    std::unordered_map<char, Node *> children;
};

void add(Node *trie, const std::string &key){
    for (const auto c : key) {
        if (trie->children.find(c) == trie->children.end()) {
            trie->children[c] = new Node();
        }
        trie = trie->children[c];
    }

    trie->end_node = true;
}

bool is_compound_word(Node *trie, const std::string &word, const int index, const int count){
    Node* node = trie;

    for (int i = index; i < word.length(); i++) {
        if (node->children.find(word[i]) == node->children.end()) {
            return false;
        }

        node = node->children[word[i]];

        if (node->end_node) {
            if (i == word.length() - 1) {
                return count >= 1;
            }

            if (is_compound_word(trie, word, i + 1, count + 1)) {
                return true;
            }
        }
    }

    return false;
}


void free(Node *trie){
    if (trie != nullptr) {
        for (auto [_, node] : trie->children) {
            free(node);
        }
        delete trie;
    }
}

int main (){
    int n; std::cin >> n;

    std::vector<std::string> words(n);
    for(int i = 0; i < n; i++) {
        std::cin >> words[i];
    }

    Node *trie = new Node();

    for (const auto &word : words) {
        add(trie, word);
    }

    std::set<std::string> compound_words;
    for (const auto &word : words) {
        if (is_compound_word(trie, word, 0, 0)) {
            compound_words.insert(word);
        }
    }

    for (const auto &word : compound_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    free(trie);

    return 0;
}