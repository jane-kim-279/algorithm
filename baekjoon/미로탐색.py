'''
백준 미로탐색
https://www.acmicpc.net/problem/2178
'''

from collections import deque

N, M = map(int, input().split())

graph = []

for _ in range(N):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    # 아직 방문해야 하는 노드가 있다면
    while queue:
        # 큐에서 노드 꺼내서 저장
        x, y = queue.popleft()

        # 4가지 방향으로 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 위치가 벗어날 경우
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue

            # 길 없음
            if graph[nx][ny] == 0:
                continue

            # 길 있음
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))

    return graph[N-1][M-1]

print(bfs(0, 0))
