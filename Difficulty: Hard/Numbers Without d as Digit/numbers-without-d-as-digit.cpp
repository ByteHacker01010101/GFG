class Solution {
    long long dp[20][2][2][2];

    long long dfs(string &s, int pos, int tight, int started,
                  int found, int d) {

        if (pos == s.size())
            return found;

        long long &res = dp[pos][tight][started][found];

        if (res != -1)
            return res;

        res = 0;

        int limit = tight ? (s[pos] - '0') : 9;

        for (int dig = 0; dig <= limit; dig++) {

            int ntight = tight && (dig == limit);

            int nstarted = started || (dig != 0);

            int nfound = found;


            if (nstarted && dig == d)
                nfound = 1;

            res += dfs(s, pos + 1, ntight,
                       nstarted, nfound, d);
        }

        return res;
    }

public:
    long long countWithout(long long n, int d) {

        if (n == 0)
            return 0;

        string s = to_string(n);

        memset(dp, -1, sizeof(dp));

        long long containing = dfs(s, 0, 1, 0, 0, d);

        return n - containing;
    }
};