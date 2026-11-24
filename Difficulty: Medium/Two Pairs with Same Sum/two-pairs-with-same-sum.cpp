class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        size_t total = (size_t)n * (n - 1) / 2;

        int bits = 1;
        while ((1u << bits) < 2 * total + 2) bits++;
        unsigned M = 1u << bits, mask = M - 1;

        vector<int> key(M, -1), head(M, -1), tail(M, -1);
        vector<int> na, nb, nxt;
        na.reserve(total); nb.reserve(total); nxt.reserve(total);

        bool has = false;
        int bA = 0, bB = 0, bC = 0, bD = 0;

        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                int s = arr[a] + arr[b];
                unsigned h = ((unsigned)s * 2654435761u) >> (32 - bits);
                while (key[h] != -1 && key[h] != s) h = (h + 1) & mask;

                bool storable = !has || a < bA || (a == bA && b < bB);

                if (key[h] == -1) {
                    if (!storable) continue;
                    key[h] = s;
                    na.push_back(a); nb.push_back(b); nxt.push_back(-1);
                    head[h] = tail[h] = (int)na.size() - 1;
                    continue;
                }

                for (int x = head[h]; x != -1; x = nxt[x]) {
                    int pa = na[x], pb = nb[x];
                    if (has && (pa > bA || (pa == bA && pb >= bB))) break;
                    if (pa != a && pa != b && pb != a && pb != b) {
                       
                        has = true;
                        bA = pa; bB = pb; bC = a; bD = b;
                        break;
                    }
                }

                if (storable) {
                    na.push_back(a); nb.push_back(b); nxt.push_back(-1);
                    int id = (int)na.size() - 1;
                    nxt[tail[h]] = id;
                    tail[h] = id;
                }
            }
        }

        if (!has) return {-1, -1, -1, -1};
        return {bA, bB, bC, bD};
    }
};