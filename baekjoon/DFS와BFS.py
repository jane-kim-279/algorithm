'''
백준 DFS와 BFS
https://www.acmicpc.net/problem/1260
'''

'''
#1. True/False로 구현

from collections import deque
  
N, M, V = map(int, input().split())

graph = [[False] * (N+1) for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = True
    graph[b][a] = True

visited1 = [False] * (N+1) #dfs 방문기록
visited2 = [False] * (N+1) #bfs 방문기

def dfs(v):
    visited1[v] = True
    print(v, end=' ')
    for i in range(1, N+1):
        if not visited1[i] and graph[v][i]:
            dfs(i)

def bfs(v):
    q = deque()
    q.append(v)
    visited2[v] = True

    # 아직 방문해야 하는 노드가 있다면
    while q:
        # 큐에서 노드 꺼내서 저장
        x = q.popleft()
        print(x, end=' ')
        for i in range(1, N+1):
            if not visited2[i] and graph[x][i]:
                q.append(i)
                visited2[i] = True

dfs(V)
print()
bfs(V)
'''

#정점 저장만으로 풀이
from collections import deque

N, M, V = map(int, input().split())
graph = [[] for _ in range(N+1)]

visited1 = [False] * (N+1)
visited2 = [False] * (N+1)

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph:
    i.sort()

def dfs(v):
    visited1[v] = True
    print(v, end=" ")
    for i in graph[v]:
        if not visited1[i]:
            dfs(i)

def bfs(v):
    q = deque()
    q.append(v)
    visited2[v] = True
    while q:
        x = q.popleft()
        print(x, end=" ")
        for i in graph[x]:
            if not visited2[i]:
                q.append(i)
                visited2[i] = True

dfs(V)
print()
bfs(V)
