class Solution {
public:
    int count(int n, int m) {
        vector<long long> prev(m + 1, 1), curr(m + 1, 0);

        if (n == 1) return m;

        for (int len = 2; len <= n; len++) {
            fill(curr.begin(), curr.end(), 0);

            for (int last = 1; last <= m; last++) {
                for (int pre = 1; pre <= m; pre++) {
                    if (last % pre == 0 || pre % last == 0)
                        curr[last] += prev[pre];
                }
            }

            prev = curr;
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++)
            ans += prev[i];

        return ans;
    }
};