def fibo(N):
    if (memo[N] == -1):
        if (N == 0):
            return 0
        elif (N == 1):
            return 1
        memo[N] = fibo(N - 1) + fibo(N - 2)
    return memo[N]


memo = [-1 for i in range(91)]
print(fibo(int(input())))
