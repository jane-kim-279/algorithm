'''
백준 정렬, 이진탐색 - 수 찾기
https://www.acmicpc.net/problem/1920
'''

def binary_search(target, num_list):
    start, end = 0, N-1
    
    while start <= end:
        mid = (start + end) // 2
        
        if num_list[mid] == target:
            return True
        
        elif num_list[mid] < target:
            start = mid + 1
        
        else:
            end = mid - 1
      
    return False
    
N = int(input())
A = list(map(int, input().split()))
M = int(input())
arr = list(map(int, input().split()))
A.sort()

for i in arr:
    if binary_search(i, A):
        print(1)
    else:
        print(0)
