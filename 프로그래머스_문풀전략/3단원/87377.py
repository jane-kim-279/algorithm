'''
교점에 별 만들기
https://school.programmers.co.kr/learn/courses/30/lessons/87377
'''

def solution(line):
    pos, answer = [], []
    n = len(line) #직선의 개수
    
    x_min = y_min = int(1e15)
    x_max = y_max = -int(1e15)
    
    #직선의 교점 구하기
    for i in range(n): 
        a, b, e = line[i]
        for j in range(i + 1, n):
            c, d, f = line[j]
            if a * d == b * c: continue
            x = (b * f - e * d) / (a * d - b * c)   
            y = (e * c - a * f) / (a * d - b * c)

            #정수인 교점만 저장
            if x == int(x) and y == int(y):
                x = int(x)
                y = int(y)
                pos.append([x, y])
                if x_min > x: x_min = x
                if y_min > y: y_min = y
                if x_max < x: x_max = x
                if y_max < y: y_max = y

    #교점 표시할 수 있는 최소 크기 사각형 구하기
    x_len = x_max - x_min + 1
    y_len = y_max - y_min + 1
    cord = [['.'] * x_len for _ in range(y_len)]

    #좌표가 음수인 경우 고려하여 보정 (영점(0, 0)을 기준으로)
    for star_x, star_y in pos:
        nx = star_x + abs(x_min) if x_min < 0 else star_x - x_min
        ny = star_y + abs(y_min) if y_min < 0 else star_y - y_min
        cord[ny][nx] = '*'
      
    #좌표 찍기    
    for result in cord: answer.append(''.join(result))

    #정답 역순 제출
    return answer[::-1]
