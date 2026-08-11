class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries,
                              int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1]
                 - pref[r1][c2 + 1]
                 - pref[r2 + 1][c1]
                 + pref[r1][c1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];

            if (mat[i][j] > k) {
                ans.push_back(-1);
                continue;
            }

            int maxRadius = min({
                i,
                j,
                n - 1 - i,
                m - 1 - j
            });

            int low = 0;
            int high = maxRadius;
            int best = 0;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int top = i - mid;
                int bottom = i + mid;
                int left = j - mid;
                int right = j + mid;

                int ones = getSum(top, left, bottom, right);

                if (ones <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};