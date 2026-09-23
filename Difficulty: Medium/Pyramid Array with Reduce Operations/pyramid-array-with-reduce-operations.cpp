class Solution {
  public:
    long long formPyramid(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        for (int x : arr) total += x;

        if (n <= 2) return total - 1;

        vector<int> left(n), right(n);
        left[0] = 1;
        for (int i = 1; i < n; ++i)
            left[i] = min(arr[i], left[i - 1] + 1);

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
            right[i] = min(arr[i], right[i + 1] + 1);

        long long maxSum = 0;
        for (int i = 0; i < n; ++i) {
            int h = min(left[i], right[i]);
            maxSum = max(maxSum, 1LL * h * h);
        }
        return total - maxSum;
    }
};