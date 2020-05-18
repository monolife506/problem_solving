N = int(input())
A = list(map(int, input().split()))
dp = [A[i] for i in range(N)]

for i in range(N - 1):
    for j in range(i, N):
        if (A[i] < A[j] and dp[i] + A[j] > dp[j]):
            dp[j] = dp[i] + A[j]

print(max(dp))
