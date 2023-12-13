'''
백준 섬의 개수 
https://www.acmicpc.net/problem/4963
'''

from collections import deque

dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, -1, 1, -1, 1]

def bfs(x, y):
    q = deque()
    q.append([x, y])
    graph[y][x] = 0     #방문처리

    while q:
        x, y = q.popleft()

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= W or ny >= H:
                continue
            if graph[ny][nx] == 1:  #섬이 있는 경우
                q.append([nx, ny])
                graph[ny][nx] = 0

while True:
    W, H = map(int, input().split())
    graph = list()

    if W == 0 and H == 0:
        break

    for _ in range(H):
        graph.append(list(map(int, input().split())))

    count = 0
    for h in range(H):
        for w in range(W):
            if graph[h][w] == 1:
                bfs(w, h)
                count += 1
    print(count)
