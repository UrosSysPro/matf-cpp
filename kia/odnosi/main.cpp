#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<pair<int, double>> base;
vector<int> rang;

void UF_init(int n)
{
    base.resize(n);
    rang.resize(n);

    for (int i = 0; i < n; i++) {
        base[i] = { i, 1.0 };
        rang[i] = 0;
    }
}

// [fx, wx] = UF_find(x) --> x = wx * fx
pair<int, double> UF_find(int x)
{
    if (x != base[x].first) {
        auto [fpx, wpx] = UF_find(base[x].first);

        base[x].first = fpx;
        base[x].second *= wpx;
    }

    return base[x];
}

void UF_union(int x, int y, double w)
{
    auto [fx, wx] = UF_find(x);
    auto [fy, wy] = UF_find(y);

    if (fx == fy) return;

    if (rang[fx] < rang[fy]) {
        base[fx] = { fy, (w * wy) / wx };
    } else if (rang[fy] < rang[fx]) {
        base[fy] = { fx, wx / (w * wy) };
    } else {
        base[fx] = { fy, (w * wy) / wx };
        rang[fy]++;
    }
}

int main()
{
    int n, q; cin >> n >> q;

    vector<tuple<string, string, double>> ratios(n);
    vector<pair<string, string>> queries(q);

    for (int i = 0; i < n; i++) {
        string x, y; double w;
        cin >> x >> y >> w;
        ratios[i] = { x, y, w };
    }

    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        queries[i] = { a, b };
    }

    int ind = 0;
    unordered_map<string, int> id;
    for (const auto &[x, y, _] : ratios) {
        if (id.find(x) == id.end()) {
            id[x] = ind++;
        }
        if (id.find(y) == id.end()) {
            id[y] = ind++;
        }
    }

    UF_init(id.size());

    for (const auto &[x, y, w] : ratios) {
        UF_union(id[x], id[y], w);
    }

    for (const auto &[a, b] : queries) {
        if (id.find(a) == id.end() ||
            id.find(b) == id.end()) {
            cout << -1 << " ";
            continue;
        }

        auto [fa, wa] = UF_find(id[a]);
        auto [fb, wb] = UF_find(id[b]);

        if (fa != fb) {
            cout << -1 << " ";
            continue;
        }

        cout << wa / wb << " ";
    }
    cout << endl;

    return 0;
}