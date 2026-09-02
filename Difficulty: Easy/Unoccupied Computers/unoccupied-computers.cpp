class Solution {
public:
    int solve(int n, string s) {
        set<char> usingComputer;
        set<char> rejected;

        int ans = 0;

        for (char c : s) {
       
            if (usingComputer.find(c) == usingComputer.end() &&
                rejected.find(c) == rejected.end()) {

                if ((int)usingComputer.size() < n) {
                    usingComputer.insert(c);
                } else {
                    rejected.insert(c);
                    ans++;
                }
            }
    
            else {
              
                if (usingComputer.find(c) != usingComputer.end()) {
                    usingComputer.erase(c);
                }
            }
        }

        return ans;
    }
};