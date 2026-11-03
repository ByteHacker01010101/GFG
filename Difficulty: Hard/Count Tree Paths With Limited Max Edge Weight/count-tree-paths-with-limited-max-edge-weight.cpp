class Solution {
  public:
    vector<int> maximumWeight(int n, vector<vector<int>>& edges,
                              vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);

        sort(edges.begin(), edges.end(),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        vector<int> parent(n + 1), sz(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        long long paths = 0;
        int j = 0;

        for (auto [limit, idx] : q) {
            while (j < edges.size() && edges[j][2] <= limit) {
                int u = find(edges[j][0]);
                int v = find(edges[j][1]);

                if (u != v) {
                    paths += 1LL * sz[u] * sz[v];

                    if (sz[u] < sz[v])
                        swap(u, v);

                    parent[v] = u;
                    sz[u] += sz[v];
                }
                j++;
            }

            ans[idx] = paths;
        }

        return ans;
    }
};