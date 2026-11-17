
class Solution {
  public:
    bool findPattern(string s) {
        int i = 0, n = s.size();

        while (i < n) {
            int cntX = 0, cntY = 0;

            while (i < n && s[i] == 'x') {
                cntX++;
                i++;
            }

            while (i < n && s[i] == 'y') {
                cntY++;
                i++;
            }

            if (cntX == 0 || cntX != cntY)
                return false;
        }

        return true;
    }
};
