from math import gcd

class Solution:
    def sameMod(self, arr):
        g = 0

        # Find GCD of differences
        for i in range(1, len(arr)):
            g = gcd(g, abs(arr[i] - arr[0]))

        # All elements are equal
        # This also handles a single-element array
        if g == 0:
            return -1

        # Count positive divisors of g
        count = 0
        i = 1

        while i * i <= g:
            if g % i == 0:
                count += 1

                if i != g // i:
                    count += 1

            i += 1

        return count