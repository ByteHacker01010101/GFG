
class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        int cnt = 0;

        for (int i = 0; i < adj.size(); i++) {
            cnt += adj[i].size();
        }

        return cnt / 2;
    }
};
