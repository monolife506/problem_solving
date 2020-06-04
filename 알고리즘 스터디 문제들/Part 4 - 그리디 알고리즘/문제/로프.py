from sys import stdin

N = int(stdin.readline())
W = [int(stdin.readline()) for i in range(N)]
W.sort(reverse=True)

ans = 0
for i in range(N):
    if (ans < W[i] * (i + 1)):
        ans = W[i] * (i + 1)
print(ans)
