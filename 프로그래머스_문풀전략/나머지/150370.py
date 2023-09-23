'''
프로그래머스 2023 카카오 블라인드 (개인정보 수집 유효기간)

https://school.programmers.co.kr/learn/courses/30/lessons/150370
'''

def calc_date(today):
    year, month, day = map(int, today.split("."))
    return year * 12 * 28 + month * 28 + day

def solution(today, terms, privacies):
    answer = []
    #오늘 날짜
    today_date = calc_date(today)
    #약관 매핑
    term_map = {term[0]: int(term[2:]) for term in terms}
    #비교
    for index, privacy in enumerate(privacies):
        duration = term_map[privacy[-1]]
        expire_date = calc_date(privacy[:-2]) + duration * 28
        #출력해보면 오늘 날짜 2022.05.19와 보관 가능 날짜 2022.05.18의 date가 같음.. 그래서 등호 포함
        if expire_date <= today_date:
            answer.append(index + 1)
    return answer
