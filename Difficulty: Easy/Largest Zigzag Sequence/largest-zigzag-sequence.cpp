class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp(n);

        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {

            int max1 = -1;
            int max2 = -1;
            int maxIndex = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > max1) {
                    max2 = max1;
                    max1 = dp[j];
                    maxIndex = j;
                }
                else if (dp[j] > max2) {
                    max2 = dp[j];
                }
            }

            vector<int> newDp(n);

            for (int j = 0; j < n; j++) {

                if (j != maxIndex)
                    newDp[j] = mat[i][j] + max1;
                else
                    newDp[j] = mat[i][j] + max2;
            }

            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};