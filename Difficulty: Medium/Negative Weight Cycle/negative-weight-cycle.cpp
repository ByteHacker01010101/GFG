class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<long long> dist(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;

                    if (i == V - 1) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};