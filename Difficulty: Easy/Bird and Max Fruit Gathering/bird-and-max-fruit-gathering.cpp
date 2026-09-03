class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        m = min(m, n);
        
        long long windowSum = 0;
        
        for (int i = 0; i < m; i++){
            windowSum += arr[i];
        }
        
        long long ans = windowSum;
        
        for (int i =m; i < n + m - 1; i++){
            windowSum += arr[i % n];
            windowSum -= arr[(i - m) % n];
            
            ans = max(ans, windowSum);
        }
        return ans;
    }
};