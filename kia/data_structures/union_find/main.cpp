#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rang;

public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rang = vector<int>(n);
        for (int i=0; i<n; i++) {
            parent[i] = i;
            rang[i] = 0;
        }
    }
    ~UnionFind(){}

    void combine(int a, int b) {
        if (find(a) == find(b))return;

        if (rang[a]==rang[b]) {
            parent[b] = a;
            rang[a]++;
            return;
        }

        if (rang[a] > rang[b]) {
            parent[b] = a;
            return;
        }

        if (rang[a] < rang[b]) {
            parent[a] = b;
            return;
        }
    }

    int find(int a) {
        if (parent[a] == a)
            return a;
        else
            return find(parent[a]);
    }

    int inSameSet(int a, int b) {
        return find(a) == find(b);
    }

    void print() {
        printf("%20s", "elements");
        for (int i=0;i<parent.size();i++) {
            printf("%3d",i);
        }
        printf("\n");

        printf("%20s", "parent");
        for (const int a : parent) {
            printf("%3d",a);
        }
        printf("\n");

        printf("%20s", "rang");
        for (const int a : rang) {
            printf("%3d",a);
        }
        printf("\n");
    }
};

int main(int argc, const char** argv) {
    UnionFind uf = UnionFind(10);
    uf.combine(2,3);
    uf.combine(4,5);
    uf.combine(2,4);
    uf.print();
    printf("3 i 5 su u istom skupu %d", uf.inSameSet(3,5));
}
