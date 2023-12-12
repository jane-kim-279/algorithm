'''
백준 유기농 배추
https://www.acmicpc.net/problem/1012
'''

import sys
sys.setrecursionlimit(10 ** 6)  #파이썬의 재귀함수 깊이가 1000까지로 얕음. 임의로 늘려줌

T = int(input())

def dfs(x, y):
    if x < 0 or y < 0 or x >= M or y >= N:    #재귀 호출 시 좌표 범위 확인
        return False
    if graph[x][y] == 1:    #배추가 심어져 있는 경우
        graph[x][y] = 0     #방문처리
        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)
        return True
    return False    #배추가 심어져 있지 않은 경우

for t in range(T):
    M, N, K = map(int, input().split())
    graph = [[0] * N for _ in range(M)]    #N, M이 헷갈림...

    for k in range(K):
        x, y = map(int, input().split())
        graph[x][y] = 1
    #print(graph)

    total = 0
    for i in range(M):
        for j in range(N):
            if dfs(i, j) == True:
                total += 1
    print(total)
