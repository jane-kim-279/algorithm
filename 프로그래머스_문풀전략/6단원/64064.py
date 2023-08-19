''''
프로그래머스 불량 사용자
https://school.programmers.co.kr/learn/courses/30/lessons/64064
'''

import re

def search(idx, visit, userId, answer, banPatterns):
    if idx == len(banPatterns):
        answer.add(visit)
        return
    for i in range(len(userId)):
        if (visit & (1 << i)) > 0 or not re.fullmatch(banPatterns[idx], userId[i]):
            search(idx + 1, visit | (1 << i), userId, answer, banPatterns)
            
def solution(user_id, banned_id):
    answer = set()
    banPatterns = [x.replace('*', '.') for x in bannedId]
    search(0, 0, userId, answer, banPatterns)
    
    return len(answer)
