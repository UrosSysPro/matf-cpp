#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char** argv) {

    int n, q;
    std::cin >> n >> q;

    std::map<std::string, std::vector<std::string>> autocomplete;

    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;

        for (int i = 0; i <= word.size(); i++) {
            autocomplete[word.substr(0, i)].push_back(word);
        }
    }

    for (int i = 0; i < q; i++) {
        std::string query;
        std::cin >> query;

        for (auto word : autocomplete[query]) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}