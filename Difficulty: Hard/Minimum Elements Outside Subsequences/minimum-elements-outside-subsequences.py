class Solution:
    def minCount(self, arr):
        n = len(arr)

      
        INF = 101
        dp = [[-1] * INF for _ in range(INF)]

        dp[0][0] = 0

        for x in arr:
            new_dp = [row[:] for row in dp]

            for inc in range(INF):
                for dec in range(INF):
                    if dp[inc][dec] == -1:
                        continue

                    used = dp[inc][dec]

                    
                    if inc == 0 or x > inc:
                        new_dp[x][dec] = max(
                            new_dp[x][dec],
                            used + 1
                        )

                    if dec == 0 or x < dec:
                        new_dp[inc][x] = max(
                            new_dp[inc][x],
                            used + 1
                        )

            dp = new_dp

        max_used = 0

        for inc in range(INF):
            for dec in range(INF):
                max_used = max(max_used, dp[inc][dec])

        return n - max_used