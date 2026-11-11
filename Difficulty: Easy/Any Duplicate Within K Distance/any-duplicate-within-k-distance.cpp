
class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_set<int> s;

        for (int i = 0; i < arr.size(); i++) {
            if (s.find(arr[i]) != s.end()) {
                return true;
            }

            s.insert(arr[i]);

            if (s.size() > k) {
                s.erase(arr[i - k]);
            }
        }

        return false;
    }
};
