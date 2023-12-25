'''
백준 곱셈
https://www.acmicpc.net/problem/1629
'''

a, b, c = map(int, input().split())

def pow(a, b, m):
    if b == 1:
        return a % m
    elif b % 2 == 0:
        return (pow(a, b//2, m)**2) % m
    else:
        return ((pow(a, b//2, m)**2)*a) % m
        
print(pow(a, b, c))
