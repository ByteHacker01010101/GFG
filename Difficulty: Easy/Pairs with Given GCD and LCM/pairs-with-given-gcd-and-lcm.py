class Solution:
    def pairCount(self, x, y):
        if y % x != 0:
            return 0

        n = y // x
        count = 0

        p = 2

        while p * p <= n:
            if n % p == 0:
                count += 1

                while n % p == 0:
                    n //= p

            p += 1

        if n > 1:
            count += 1

        return 2 ** count