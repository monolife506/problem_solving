# 11047번 : 동전 0
import sys

# 입력
N, K = map(int, sys.stdin.readline().split())
money = list()
for i in range(N) :
    money.append(int(sys.stdin.readline()))

# 계산
money.sort(reverse=True); count = 0
for i in money :
    count += K // i
    K = K % i

# 출력
print(count)