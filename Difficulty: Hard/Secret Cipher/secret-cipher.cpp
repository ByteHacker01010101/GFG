class Solution {
public:
    string compress(string s) {
        int n = s.size();

        
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];

            if (s[i] == s[j])
                j++;

            lps[i] = j;
        }

        string ans;

        int i = n - 1;

        while (i >= 0) {

           
            if (i % 2 == 1) {

                int len = i + 1;
                int half = len / 2;

             
                
                if (lps[i] >= half &&
                    len % (2 * (len - lps[i])) == 0) {

                    ans.push_back('*');

                    i = half - 1;

                    continue;
                }
            }

            ans.push_back(s[i]);
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};