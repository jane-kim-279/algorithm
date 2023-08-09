'''
프로그래머스 문자열 압축 (2020 카카오 블라인드 문제)
https://school.programmers.co.kr/learn/courses/30/lessons/60057
'''

def solution(s):
    answer = len(s)
    for x in range(1, len(s) // 2 + 1):
        rep_len = 0
        rep = ''
        cnt = 1
        for i in range(0, len(s) + 1, x):
            temp = s[i:i + x]
            if rep == temp: cnt += 1
            elif rep != temp:
                rep_len += len(temp)
                if cnt > 1: rep_len += len(str(cnt))
                cnt = 1
                rep = temp
        answer = min(answer, rep_len)

    return answer
