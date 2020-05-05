from sys import stdin

N = int(stdin.readline())
T = [int(stdin.readline()) for i in range(N)]
T.sort(reverse=True)

total = 0
for i in range(N):
    if (T[i] - i > 0):
        total += (T[i] - i)
    else:
        break
print(total)
