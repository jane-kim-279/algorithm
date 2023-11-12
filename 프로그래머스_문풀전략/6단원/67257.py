'''
프로그래머스 수식 최대화
https://school.programmers.co.kr/learn/courses/30/lessons/67257
'''

from itertools import permutations
import re

#후위 표기법으로 교체
def toPostFix(tokens, priority):
    stack = []      #연산자 스택
    postfix = []    #출력 배열
    
    for token in tokens:                             #분리된 전체 식을 iterate
        if token.isdigit(): postfix.append(token)    #숫자는 그대로 출력
        else:
            if not stack: stack.append(token)        #스택이 비었으면 연산자를 스택에 추가
            else:        
                while stack:                         #안 비었다면
                    if priority[token] <= priority[stack[-1]]: #연산자끼리 우선순위 비교해서
                        postfix.append(stack.pop()) #낮으면 낮지 않을때까지 기존 스택 비우기(출력)
                    else: break
                        
                stack.append(token)    #마지막에는 자기 자신(연산자) 추가
                
    while stack:                       #연산자가 남으면
        postfix.append(stack.pop())    #남는 연산자 털기(출력)
        
    return postfix

#후위 표기법 계산식 계산
def calc(tokens):
    stack = []
    
    for token in tokens:
        if token.isdigit():
            stack.append(int(token))
            continue
        
        num1 = stack.pop()
        num2 = stack.pop()
        if token == '*':
            stack.append(num2 * num1)
        elif token == '+':
            stack.append(num2 + num1)
        else: #'-'
            stack.append(num2 - num1)
    
    return stack.pop()

def solution(expression):
    tokens = re.split(r'([-=*/()])|\s+', expression)
    operators = ['+', '-', '*']
    answer = 0

    #연산자 우선순위를 순열로 만들고, 이를 for문으로 순회함
    for i in map(list, permutations(operators)):
        #precedence and operator
        priority = {o:p for p, o in enumerate(list(i))}
        postfix = toPostFix(tokens, priority)
        #최대 절대값이 원하는 결과
        answer = max(answer, abs(calc(postfix)))
    
    return answer
