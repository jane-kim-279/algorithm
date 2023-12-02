'''
백준 숨바꼭질
https://www.acmicpc.net/problem/1697
'''

from collections import deque

MAX = 100001
N, K = map(int, input().split())
dist = [0] * MAX

def bfs(x):
    q = deque()
    q.append(x)

    # 아직 방문해야 하는 노드가 있다면
    while q:
        # 큐에서 노드 꺼내서 저장
        x = q.popleft()

        if x == K:
            return dist[x]

        for nx in (x-1, x+1, x*2):
            if 0 <= nx < MAX and not dist[nx]:
                dist[nx] = dist[x] + 1
                q.append(nx)


print(bfs(N))
