class Solution:
    def maxProduct(self, arr, k):
        INF = float('inf')

        max_dp = [-INF] * (k + 1)
        min_dp = [INF] * (k + 1)

        max_dp[0] = 1
        min_dp[0] = 1

        for x in arr:
            # Go backwards so each element is used at most once
            for j in range(k, 0, -1):

                if max_dp[j - 1] != -INF:
                    max_dp[j] = max(
                        max_dp[j],
                        max_dp[j - 1] * x,
                        min_dp[j - 1] * x
                    )

                if min_dp[j - 1] != INF:
                    min_dp[j] = min(
                        min_dp[j],
                        max_dp[j - 1] * x,
                        min_dp[j - 1] * x
                    )

        return max_dp[k]