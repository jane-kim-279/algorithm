'''
프로그래머스 이진 변환 반복하기
https://school.programmers.co.kr/learn/courses/30/lessons/70129
'''

def solution(s):
    change, zeros = 0, 0
    while s != '1':
        change += 1
        ones = s.count('1')
        zeros += len(s) - ones
        s = bin(ones)[2:]
    return [change, zeros]
