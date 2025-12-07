#include <iostream>
#include <vector>

/*
Naivni autocomplete

Neka je dat rečnik od n

reči. Upit je niska za koji treba ispisati sve reči iz rečnika za koje je taj upit prefiks.
Opis ulaza

Sa standardnog ulaza se učitavaju celi brojevi n
i q, a zatim i n reči rečnika. Nakon toga, učitava se q

upita, svaki u zasebnom redu.
Opis izlaza

Za svaki od upita, na standardni izlaz, ispisati sve reči iz rečnika za koje je on prefiks.
Primer
Ulaz

5 3
code coder codecs coding coders cod
code
co
codd

Izlaz

code coder codecs coders
code coder codecs coding coders cod
*/
int main(int argc, char** argv) {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        std::string query;
        std::cin >> query;

        if (query == "u") {
            int ind, val;
            std::cin >> ind >> val;
            a[ind] = val;
        } else if (query == "s") {
            int l, r;
            std::cin >> l >> r;

            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum += a[i];
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}