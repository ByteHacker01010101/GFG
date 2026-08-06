class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int doubles = 0;

        for (int x : arr) {
            int bits = 0;

            while (x > 0) {
                if (x & 1)
                    increments++;
                x >>= 1;
                bits++;
            }

            doubles = max(doubles, max(0, bits - 1));
        }

        return increments + doubles;
    }
};