'''
프로그래머스 짝지어 제거하기 (2017 팁스타운)
https://school.programmers.co.kr/learn/courses/30/lessons/12973
'''

def solution(s):
    stack = []
    for case in s:
        if stack and stack[-1] == case : stack.pop()
        else: stack.append(case)
        
    return 0 if stack else 1

'''
시간초과, 효율성 탈락 코드
def solution(s):
    while len(s) > 1:
        s = list(s)
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]: s[i] = s[i + 1] = '' #중복 문자를 공백으로 변경
            
        new_s = ''.join(s) #문자열로 합치며 공백 자동 제거
        if len(s) == len(new_s): break #변화가 없으면 제거하지 못했으므로 반복문 탈출
        s = new_s
        
    return 1 if len(s) == 0 else 0
'''
