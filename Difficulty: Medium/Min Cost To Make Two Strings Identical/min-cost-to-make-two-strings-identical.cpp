class Solution {
public:
    int findMinCost(string s1, string s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        int lcs = prev[m];

        return (n - lcs) * costS1 + (m - lcs) * costS2;
    }
};