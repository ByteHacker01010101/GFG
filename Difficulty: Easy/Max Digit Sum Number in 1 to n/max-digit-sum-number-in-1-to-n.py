class Solution:
    def findMax(self, n):
        def digit_sum(x):
            return sum(map(int, str(x)))

        s = str(n)

        best = n
        best_sum = digit_sum(n)

        for i in range(len(s)):
            if s[i] == '0':
                continue

            candidate = int(
                s[:i] +
                str(int(s[i]) - 1) +
                '9' * (len(s) - i - 1)
            )

            current_sum = digit_sum(candidate)

            if current_sum > best_sum:
                best = candidate
                best_sum = current_sum
            elif current_sum == best_sum and candidate > best:
                best = candidate

        return best