typedef struct DSU
{
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i;
        rank.resize(n, 0);
    }

    void makeSet(int v) {
        par[v] = v;
        rank[v] = 1;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionSet(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) swap(u, v);
            par[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }
}DSU;