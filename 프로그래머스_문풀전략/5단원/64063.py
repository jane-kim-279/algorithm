'''
프로그래머스 호텔 방 배정
https://school.programmers.co.kr/learn/courses/30/lessons/64063
'''

import sys
sys.setrecursionlimit(200)

def solution(k, room_number):
    rooms = dict() #할당된 방 정보만 저장
    for num in room_number:
        chk_in = find_emptyroom(num, rooms)
    return list(rooms)

def find_emptyroom(chk, rooms):
    if chk not in rooms:
        rooms[chk] = chk + 1
        return chk
    empty = find_emptyroom(rooms[chk], rooms)
    rooms[chk] = empty + 1
    return empty
