class Solution {
  public:
    long long minTime(int n, int s1, int s2) {
        long long x = (1LL * n * s2) / (s1 + s2);

        long long ans = LLONG_MAX;

        for (long long i = max(0LL, x - 1); i <= min((long long)n, x + 1); i++) {
            long long t1 = i * s1;
            long long t2 = (n - i) * s2;

            ans = min(ans, max(t1, t2));
        }

        return ans;
    }
};