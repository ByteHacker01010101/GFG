class Solution:
    def pairAndSum(self, arr):
        ans = 0

        for bit in range(31):
            cnt = 0

            for x in arr:
                if x & (1 << bit):
                    cnt += 1

            pairs = cnt * (cnt - 1) // 2
            ans += pairs * (1 << bit)

        return ans