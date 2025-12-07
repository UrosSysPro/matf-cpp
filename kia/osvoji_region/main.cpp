#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rang;

void UF_init(int n)
{
    parent.resize(n);
    rang.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rang[i] = 0;
    }
}

int UF_find(int x)
{
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void UF_union(int x, int y)
{
    int fx = UF_find(x);
    int fy = UF_find(y);

    if (fx == fy) return;

    if (rang[fx] < rang[fy]) {
        parent[fx] = fy;
    } else if (rang[fy] < rang[fx]) {
        parent[fy] = fx;
    } else {
        parent[fx] = fy;
        rang[fy]++;
    }
}

int code(int i, int j, int m)
{
    return i * m + j;
}

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    UF_init(n * m + 1);

    const int dummy = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    UF_union(dummy, code(i, j, m));
                } else {
                    if (i > 0 && board[i - 1][j] == 0) {
                        UF_union(code(i, j, m), code(i - 1, j, m));
                    }
                    if (i < n - 1 && board[i + 1][j] == 0) {
                        UF_union(code(i, j, m), code(i + 1, j, m));
                    }
                    if (j > 0 && board[i][j - 1] == 0) {
                        UF_union(code(i, j, m), code(i, j - 1, m));
                    }
                    if (j < m - 1 && board[i][j + 1] == 0) {
                        UF_union(code(i, j, m), code(i, j + 1, m));
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && UF_find(dummy) != UF_find(code(i, j, m))) {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}