from sys import stdin

N, S, R = map(int, stdin.readline().split())
T = [1 for i in range(N + 2)]

listS = list(map(int, stdin.readline().split()))
for i in listS:
    T[i] -= 1
listR = list(map(int, stdin.readline().split()))
for i in listR:
    T[i] += 1

cnt = 0
for i in range(1, N + 1):
    if (T[i] == 0):
        if (i != 1 and T[i - 1] == 2):
            T[i - 1] -= 1
            continue
        if (i != N and T[i + 1] == 2):
            T[i + 1] -= 1
            continue
        cnt += 1
print(cnt)
