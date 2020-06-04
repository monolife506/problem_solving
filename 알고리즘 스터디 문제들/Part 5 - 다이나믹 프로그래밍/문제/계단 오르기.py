N = int(input())

# 타뷸레이션을 위한 배열
# ta[i][1] == 다음 계단을 밟을 수 있는 경우의 i번째 계단에서 최대 합
# ta[i][0] == 다음 계단을 밟을 수 없는 경우 i번째 계단에서 최대 합
ta = [[0, 0] for i in range(N + 1)]

# st[i] = i번째 계단의 수
st = [0 for i in range(N + 1)]
for i in range(1, N + 1):
    st[i] = int(input())

ta[0][0] = ta[0][1] = ta[1][0] = 0
ta[1][1] = st[1]
for i in range(2, N + 1):
    ta[i][0] = ta[i - 1][1] + st[i]
    ta[i][1] = max(ta[i - 2][0], ta[i - 2][1]) + st[i]
print(max(ta[N][0], ta[N][1]))
