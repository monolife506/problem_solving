memo = [0 for i in range(12)]
memo[1] = 1
memo[2] = memo[1] + 1
memo[3] = memo[2] + memo[1] + 1

for i in range(4, 12):
    memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3]

T = int(input())
for i in range(T):
    N = int(input())
    print(memo[N])
