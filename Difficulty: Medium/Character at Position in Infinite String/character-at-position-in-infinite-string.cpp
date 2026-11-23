class Solution {
  public:
    char posInfinite(string s, int pos) {
        vector<long long> lens;
        lens.push_back(s.size());
        long long k = 0;
        while (lens.back() < pos) {
            k++;
            lens.push_back(2 * lens.back() + k);
        }

        long long p = pos;
        for (int k = (int)lens.size() - 1; k >= 1; k--) {
            long long L = lens[k - 1];
            if (p <= L) continue;
            if (p <= L + k) return '$';
            p = 2 * L + k + 1 - p;
        }

        return s[p - 1];
    }
};