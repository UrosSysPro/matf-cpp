#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char **argv)
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> p(n);
    partial_sum(a.cbegin(), a.cend(), p.begin());

    for (int i = 0; i < q; i++) {
        std::string query;
        std::cin >> query;

        if (query == "u") {
            int ind, val;
            std::cin >> ind >> val;

            a[ind] = val;
            partial_sum(a.cbegin(), a.cend(), p.begin());
        } else if (query == "s") {
            int l, r;
            std::cin >> l >> r;

            std::cout << (l == 0 ? p[r] : p[r] - p[l - 1]) << std::endl;
        }
    }

    return 0;
}