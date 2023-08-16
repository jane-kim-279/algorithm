'''
프로그래머스 콜라츠 추측
https://school.programmers.co.kr/learn/courses/30/lessons/12943
'''

def collatz(num, rep):
    if num == 1: return rep
    if rep == 500: return -1

    if num % 2 == 0:
        return collatz(num // 2, rep + 1)
    elif num % 2 == 1:
        return collatz(num * 3 + 1, rep + 1)

def solution(num):
    return collatz(num, 0)
