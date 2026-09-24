class Solution {
public:

    int bit[1005];

    int query(int x) {
        int ans = 0;

        while (x > 0) {
            ans = max(ans, bit[x]);
            x -= x & -x;
        }

        return ans;
    }

    void update(int x, int val) {
        while (x <= 1000) {
            bit[x] = max(bit[x], val);
            x += x & -x;
        }
    }

    int maxStackHeight(vector<int>& r, vector<int>& h) {

        int n = r.size();

        vector<array<int, 3>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {r[i], h[i], 0};
        }

        sort(a.begin(), a.end());

        memset(bit, 0, sizeof(bit));

        int answer = 0;
        int i = 0;

        while (i < n) {

            int j = i;


            while (j < n && a[j][0] == a[i][0]) {
                j++;
            }

      
            for (int k = i; k < j; k++) {

                int height = a[k][1];

           
                int best = query(height - 1);

                a[k][2] = best + height;

                answer = max(answer, a[k][2]);
            }

          
            for (int k = i; k < j; k++) {

                int height = a[k][1];
                int dp = a[k][2];

                update(height, dp);
            }

            i = j;
        }

        return answer;
    }
};