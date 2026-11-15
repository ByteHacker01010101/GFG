class Solution {
  public:
     int subsequenceSum(string s) {
        const long long MOD = 1e9 + 7;

        long long sum = 0;
        long long power = 1;

        for (char c : s) {
            sum = (sum + (c - '0')) % MOD;
        }

        int n = s.size();

        for (int i = 1; i < n; i++) {
            power = (power * 2) % MOD;
        }

        return (sum * power) % MOD;
    }
};