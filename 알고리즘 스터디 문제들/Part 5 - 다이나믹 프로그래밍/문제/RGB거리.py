N = int(input())

# j에 대해 R = 0, G = 1, B = 2
# val[i][j] = i번째 집을 j색으로 칠하는데 드는 비용
val = [list(map(int, input().split())) for i in range(N)]

# total[i][j] = i번째 집까지 색을 칠하고 i번째 집의 색이 j일 때
# 지금까지 칠한 비용의 합의 최솟값
total = [[0, 0, 0] for i in range(N)]

total[0][0] = val[0][0]
total[0][1] = val[0][1]
total[0][2] = val[0][2]
for i in range(1, N):
    total[i][0] = min(total[i - 1][1], total[i - 1][2]) + val[i][0]
    total[i][1] = min(total[i - 1][0], total[i - 1][2]) + val[i][1]
    total[i][2] = min(total[i - 1][0], total[i - 1][1]) + val[i][2]
print(min(total[N - 1]))
