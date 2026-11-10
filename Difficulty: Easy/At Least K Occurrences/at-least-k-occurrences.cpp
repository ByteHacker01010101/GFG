class Solution {
  public:
    int firstElementKTime(vector<int> &arr, int k) {
        unordered_map<int, int> mp;

        for (int x : arr) {
            mp[x]++;

            if (mp[x] == k) {
                return x;
            }
        }

        return -1;
    }
};