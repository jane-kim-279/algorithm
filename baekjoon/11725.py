'''
백준 트리의 부모 찾기
https://www.acmicpc.net/problem/11725
'''

from collections import deque

N = int(input())
graph = [[] for _ in range(N+1)]
parent = [0 for _ in range(N+1)]

def bfs(start):
    q = deque()
    q.append(start)
    while q:
        v = q.popleft()
        for i in graph[v]:
            if parent[i] == 0:
                parent[i] = v
                q.append(i)

for i in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

bfs(1)

for i in parent[2:]:
    print(i)
