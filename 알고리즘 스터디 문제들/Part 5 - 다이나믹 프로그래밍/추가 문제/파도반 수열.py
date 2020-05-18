T = int(input())
P = [0 for i in range(101)]
P[1] = P[2] = 1
for i in range(3, 101):
    P[i] = P[i - 2] + P[i - 3]
for i in range(T):
    N = int(input())
    print(P[N])
