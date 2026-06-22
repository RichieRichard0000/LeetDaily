class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findparent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findparent(parent[x]);
    }

    void unite(int a, int b) {
        int pa = findparent(a);
        int pb = findparent(b);

        if (pa == pb) return;

        if (size[pa] < size[pb])
            swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1)
                    dsu.unite(i, j);
            }
        }

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.findparent(i) == i)
                provinces++;
        }

        return provinces;
    }
};