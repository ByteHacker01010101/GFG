class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> prefix(n);

        for (int i = 0; i < n; i++) {
            long long cnt = r[i] - l[i] + 1;

            if (i == 0)
                prefix[i] = cnt;
            else
                prefix[i] = prefix[i - 1] + cnt;
        }

        vector<int> ans;

        for (int k : rank) {

            int lo = 0, hi = n - 1;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (prefix[mid] >= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int i = lo;

            long long before = (i == 0) ? 0 : prefix[i - 1];

            long long position = k - before;

            long long mark = l[i] + position - 1;

            ans.push_back((int)mark);
        }

        return ans;
    }
};