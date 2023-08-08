'''
프로그래머스 2019 카카오 개발자 겨울 인턴십 문제
https://school.programmers.co.kr/learn/courses/30/lessons/64065
'''

def solution(s):
    answer = {} #배열에서 딕셔너리로 교체
    s = sorted(s[2:-2].split("},{"), key=len)
    for tuples in s:
        elements = tuples.split(',')
        for element in elements:
            number = int(element)
            if number not in answer:
                answer[number] = 1
                
    return list(answer)
