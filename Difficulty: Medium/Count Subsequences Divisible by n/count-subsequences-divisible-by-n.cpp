class Solution {
public:
    int countSubsequences(string s, int n) {
        const int MOD = 1000000007;

        vector<long long> dp(n, 0);

        for (char ch : s) {
            int d = ch - '0';

            vector<long long> old = dp;

            dp[d % n] = (dp[d % n] + 1) % MOD;

            for (int r = 0; r < n; r++) {
                if (old[r] == 0)
                    continue;

                int newRem = (r * 10LL + d) % n;

                dp[newRem] = (dp[newRem] + old[r]) % MOD;
            }
        }

        return dp[0];
    }
};