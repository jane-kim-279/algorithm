'''
백준 벽 부수고 이동하기
https://www.acmicpc.net/problem/2206
'''

from collections import deque

n, m = map(int, input().split())
graph = []

for _ in range(n):
    graph.append(list(map(int, input())))

visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]

#print(graph)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    q.append((0, 0, 0))
    visited[0][0][0] = 1    #방문처리

    while q:
        x, y, wall = q.popleft()
        if x == n -1 and y == m - 1:    #그래프 끝에 도착함
            return visited[x][y][wall]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and visited[nx][ny][wall] == 0:  #그래프 범위 내 & 아직 방문X
                if graph[nx][ny] == 0:  #벽X
                    q.append([nx, ny, wall])
                    visited[nx][ny][wall] = visited[x][y][wall] + 1
                if graph[nx][ny] == 1 and wall == 0:    #벽O, 아직 벽을 부수지 않음
                    q.append((nx, ny, 1))
                    visited[nx][ny][1] = visited[x][y][wall] + 1

    return -1

print(bfs())
