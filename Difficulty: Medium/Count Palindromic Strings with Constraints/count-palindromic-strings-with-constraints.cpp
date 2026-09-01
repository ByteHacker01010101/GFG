class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long palindromicStrings(int n, int k) {
        long long ans = 0;

     
        long long oddPerm = 1;

       
        long long evenPerm = 1;

        for (int m = 0; 2 * m + 1 <= n || 2 * m <= n; m++) {

            if (2 * m + 1 <= n) {
                long long oddCount = (k * oddPerm) % MOD;
                ans = (ans + oddCount) % MOD;
            }

     
            if (m > 0 && 2 * m <= n) {
                ans = (ans + evenPerm) % MOD;
            }

            if (m + 1 <= k) {
                evenPerm = evenPerm * (k - m) % MOD;
            }

            if (m + 1 <= k - 1) {
                oddPerm = oddPerm * (k - 1 - m) % MOD;
            }
        }

        return ans;
    }
};