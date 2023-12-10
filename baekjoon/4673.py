'''
백준 셀프넘버
https://www.acmicpc.net/problem/4673
'''

numbers = list(range(1, 10001))
remove_list = []

for num in numbers:
    for n in str(num):
        num += int(n)
    if num <= 10000:
        remove_list.append(num)
for remove_num in set(remove_list): #중복되는 숫자가 있을 수 있으니 set 사용
    numbers.remove(remove_num)
for self_num in numbers:
    print(self_num)
