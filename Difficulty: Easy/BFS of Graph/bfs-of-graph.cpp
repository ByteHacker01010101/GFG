class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();

        vector<int> vis(v, 0);
        vector<int> ans;
        queue<int> q;

        vis[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};