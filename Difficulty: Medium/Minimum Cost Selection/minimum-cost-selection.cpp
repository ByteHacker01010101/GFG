class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();

        int a = mat[0][0];
        int b = mat[0][1];
        int c = mat[0][2];

        for (int i = 1; i < n; i++) {
            int na = mat[i][0] + min(b, c);
            int nb = mat[i][1] + min(a, c);
            int nc = mat[i][2] + min(a, b);

            a = na;
            b = nb;
            c = nc;
        }

        return min(a, min(b, c));
    }
};