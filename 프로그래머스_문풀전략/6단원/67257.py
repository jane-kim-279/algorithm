'''
프로그래머스 수식 최대화
https://school.programmers.co.kr/learn/courses/30/lessons/67257
'''

from itertools import permutations
import re

#후위 표기법으로 교체
def toPostFix(tokens, priority):
    stack = []
    postfix = []
    
    for token in tokens:
        if token.isdigit(): postfix.append(token)
        else:
            if not stack: stack.append(token)
            else:
                while stack:
                    if priority[token] <= priority[stack[-1]]:
                        postfix.append(stack.pop())
                    else: break
                stack.append(token)
                
    while stack:
        postfix.append(stack.pop())
        
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
