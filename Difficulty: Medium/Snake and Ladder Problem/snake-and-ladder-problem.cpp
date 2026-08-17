class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        
        vector<int> jump(N + 1, -1);

    
        for (int i = 0; i + 1 < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }


        for (int i = 0; i + 1 < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(N + 1, false);

        queue<pair<int, int>> q;

 
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            int cell = q.front().first;
            int throws = q.front().second;
            q.pop();

            if (cell == N)
                return throws;

   
            for (int dice = 1; dice <= 6; dice++) {
                int next = cell + dice;

                if (next > N)
                    continue;

              
                if (jump[next] != -1)
                    next = jump[next];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, throws + 1});
                }
            }
        }

        return -1;
    }
};