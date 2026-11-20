
class Solution {
  public:
    int minFlips(string& s) {
        int flip1 = 0, flip2 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != (i % 2 == 0 ? '0' : '1'))
                flip1++;

            if (s[i] != (i % 2 == 0 ? '1' : '0'))
                flip2++;
        }

        return min(flip1, flip2);
    }
};
