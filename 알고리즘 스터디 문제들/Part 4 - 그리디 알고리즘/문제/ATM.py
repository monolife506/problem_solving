from sys import stdin

N = int(stdin.readline())
T = list(map(int, stdin.readline().split()))
T.sort()

total = 0
for i in range(N):
    total += (T[i] * (N - i))
print(total)
