class Solution {
public:
    long long int countBT(int h) {
        const long long MOD = 1e9 + 7;

        long long a = 1, b = 1;

        for (int i = 2; i <= h; i++) {
            long long c = (b * b + 2 * b * a) % MOD;
            a = b;
            b = c;
        }

        return b;
    }
};