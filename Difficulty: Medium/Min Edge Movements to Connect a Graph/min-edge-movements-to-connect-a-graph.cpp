class Solution {
public:

    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        if (rankv[u] < rankv[v])
            swap(u, v);

        parent[v] = u;

        if (rankv[u] == rankv[v])
            rankv[u]++;

        return true;
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                extra++;
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                components++;
            }
        }

        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};