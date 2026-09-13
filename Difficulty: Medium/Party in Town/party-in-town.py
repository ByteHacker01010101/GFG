from collections import deque

class Solution:
    def partyHouse(self, adj):
        n = len(adj)

        def bfs(start):
            dist = [-1] * n
            dist[start] = 0

            q = deque([start])
            farthest = start

            while q:
                u = q.popleft()

                if dist[u] > dist[farthest]:
                    farthest = u

                for v in adj[u]:
                    v -= 1       # houses are 1-based
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)

            return farthest, dist[farthest]

        A, _ = bfs(0)

        B, diameter = bfs(A)

        return (diameter + 1) // 2