'''
프로그래머스 3진법 뒤집기
https://school.programmers.co.kr/learn/courses/30/lessons/68935
'''

def radixChange(num, radix):
    if num == 0: return 0
    nums = []
    while num:
        num, digit = divmod(num, radix)
        nums.append(str(digit))
    return ''.join(reversed(nums))

def solution(n):
    return int(radixChange(n, 3)[::-1], 3)
