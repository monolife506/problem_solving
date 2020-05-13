from sys import stdin

N = int(stdin.readline())
memo = [-1 for i in range(91)]
memo[0] = 0
memo[1] = 1
for i in range(2, 91):
    memo[i] = memo[i - 1] + memo[i - 2]
print(memo[N])
