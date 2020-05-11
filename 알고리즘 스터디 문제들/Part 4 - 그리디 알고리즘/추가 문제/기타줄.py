from sys import stdin

N, M = map(int, stdin.readline().split())
minP = 1000
minS = 1000
for i in range(M):
    P, S = map(int, stdin.readline().split())
    if (P < minP):
        minP = P
    if (S < minS):
        minS = S

if (minS * 6 <= minP):
    print(N * minS)
else:
    total = 0
    total += (N // 6) * minP
    if ((N % 6) * minS < minP):
        total += (N % 6) * minS
    else:
        total += minP
    print(total)
