'''
백준 그림
https://www.acmicpc.net/problem/1926
'''

from collections import deque

def bfs(x, y):
    area = 1
    q = deque()
    q.append((x, y))
    visited[x][y] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))
                    area += 1

    return area


n, m = map(int, input().split())
graph = []
visited = [[False] * m for _ in range(n)]

for _ in range(n):
    graph.append(list(map(int, input().split())))

#print(graph)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

count, max_area = 0, 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1 and not visited[i][j]:
            count += 1
            max_area = max(max_area, bfs(i, j))

print(count)
print(max_area)
