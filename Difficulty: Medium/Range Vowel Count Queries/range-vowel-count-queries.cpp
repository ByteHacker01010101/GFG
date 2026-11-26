
class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];

            if (s[i] == 'a' || s[i] == 'e' || 
                s[i] == 'i' || s[i] == 'o' || 
                s[i] == 'u') {
                pref[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
