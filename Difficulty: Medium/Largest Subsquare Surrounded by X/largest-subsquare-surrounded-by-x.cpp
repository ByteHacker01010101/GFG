class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();

       
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if (j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if (i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int maxSide = min(right[i][j], down[i][j]);

            
                for (int side = maxSide; side > ans; side--) {

                    int bottom = i + side - 1;
                    int rightCol = j + side - 1;

                   
                    if (bottom >= n || rightCol >= n)
                        continue;

                   
                    if (right[bottom][j] >= side &&
                        down[i][rightCol] >= side) {

                        ans = side;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};