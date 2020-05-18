N = int(input())
con = [[0, 0] for i in range(N + 1)]
dp = [0 for i in range(N + 1)]
for i in range(N):
    con[i][0], con[i][1] = map(int, input().split())

for i in range(0, N):
    for j in range(i, N + 1):
        if (dp[j] < dp[i] + con[i][1] and j >= i + con[i][0]):
            dp[j] = dp[i] + con[i][1]

print(max(dp))
