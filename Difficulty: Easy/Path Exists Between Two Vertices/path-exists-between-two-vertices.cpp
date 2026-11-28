class Solution {
  public:
    bool checkPath(vector<vector<int>>& adj, int src, int dest) {
        int V = adj.size();

        vector<bool> vis(V, false);
        queue<int> q;

        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return true;

            for (int x : adj[node]) {
                if (!vis[x]) {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }

        return false;
    }
};