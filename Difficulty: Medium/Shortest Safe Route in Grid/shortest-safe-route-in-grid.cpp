class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 1 = safe, 0 = unsafe
        vector<vector<int>> safe(n, vector<int>(m, 1));

        // Mark mines and their adjacent cells unsafe
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    safe[i][j] = 0;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m) {
                            safe[ni][nj] = 0;
                        }
                    }
                }
            }
        }

        // BFS
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Every safe cell in first column can be a starting point
        for (int i = 0; i < n; i++) {
            if (safe[i][0]) {
                q.push({i, 0});

                // Count starting cell as 1
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Reached last column
            if (c == m - 1) {
                return dist[r][c];
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    safe[nr][nc] &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};