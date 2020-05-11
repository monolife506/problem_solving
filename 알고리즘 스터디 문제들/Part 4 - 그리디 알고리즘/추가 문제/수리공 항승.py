N, L = map(int, input().split())
P = list(map(int, input().split()))
P.sort()
cnt = 0
cur = 0
for num in P:
    if (num >= cur):
        cnt += 1
        cur = num + L
print(cnt)
