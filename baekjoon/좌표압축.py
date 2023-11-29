'''
백준 좌표 압축
https://www.acmicpc.net/problem/18870
'''

N = int(input())
num_list = list(map(int, input().split()))
sorted_list = sorted(list(set(num_list)))

dict_list = dict(zip(sorted_list, list(range(len(sorted_list)))))

for i in num_list:
    print(dict_list[i], end=" ")
