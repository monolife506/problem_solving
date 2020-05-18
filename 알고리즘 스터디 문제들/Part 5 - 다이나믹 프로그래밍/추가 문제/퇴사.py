N = int(input())
con = [[0, 0] for i in range(N + 1)]
dp = [0 for i in range(N + 1)]
for i in range(N):
    con[i][0], con[i][1] = map(int, input().split())

for i in range(1, N + 1):
    for j in range(i):
        if (dp[i] < dp[j] + con[j][1] and i >= j + con[j][0]):
            dp[i] = dp[j] + con[j][1]

print(max(dp))
