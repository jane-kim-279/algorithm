'''
백준 유기농 배추
https://www.acmicpc.net/problem/1012
'''

from collections import deque

T = int(input())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    q = deque()
    q.append((x, y))
    graph[x][y] = 0     #방문처리
    
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= M or ny >= N:
                continue
            if graph[nx][ny] == 1:  #배추가 심어져 있는 경우
                q.append((nx, ny))
                graph[nx][ny] = 0

for t in range(T):
    M, N, K = map(int, input().split())
    graph = [[0] * N for _ in range(M)]

    for k in range(K):
        x, y = map(int, input().split())
        graph[x][y] = 1
    #print(graph)

    total = 0
    for i in range(M):
        for j in range(N):
            if graph[i][j] == 1:
                bfs(i, j)
                total += 1
    print(total)
