class Solution:
    def searchWord(self, grid, word):
        n = len(grid)
        m = len(grid[0])

        # 8 possible directions
        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ]

        ans = []

        for r in range(n):
            for c in range(m):

                # Starting cell must match first character
                if grid[r][c] != word[0]:
                    continue

                # Try all 8 directions
                for dr, dc in directions:
                    found = True

                    for k in range(1, len(word)):
                        nr = r + k * dr
                        nc = c + k * dc

                        # Out of bounds
                        if nr < 0 or nr >= n or nc < 0 or nc >= m:
                            found = False
                            break

                        # Character doesn't match
                        if grid[nr][nc] != word[k]:
                            found = False
                            break

                    if found:
                        ans.append([r, c])
                        break

        return ans