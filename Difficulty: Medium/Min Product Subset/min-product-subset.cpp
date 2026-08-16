class Solution {
public:
    long long minProd(vector<int>& arr) {
        long long product = 1;
        int negCount = 0;
        int smallestNegAbs = INT_MAX;
        bool hasZero = false;
        bool hasPositive = false;

        for (int x : arr) {
            if (x == 0) {
                hasZero = true;
            }
            else if (x < 0) {
                negCount++;
                smallestNegAbs = min(smallestNegAbs, abs(x));
                product *= x;
            }
            else {
                hasPositive = true;
                product *= x;
            }
        }

        if (negCount == 0) {
            if (hasZero)
                return 0;

            int mn = INT_MAX;
            for (int x : arr)
                mn = min(mn, x);

            return mn;
        }

        if (negCount % 2 == 1)
            return product;


        return product / (-smallestNegAbs);
    }
};