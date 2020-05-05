from sys import stdin

N, K = map(int, stdin.readline().split())
A = [int(stdin.readline()) for i in range(N)]
A.reverse()

cnt = 0
for i in range(N):
    cnt += K // A[i]
    K = K % A[i]
print(cnt)
