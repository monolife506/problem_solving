# 색종이의 상태를 나타내는 배열
P = [[0 for i in range(100)] for i in range(100)]
# P[i][j] = (i, j)와 (i + 1, j + 1)을 양 점으로 하는
# 도화지 위 정사각형 구역이 검은 영역인지 확인하는 변수

N = int(input())
for t in range(N):
    X, Y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            P[X + i][Y + j] = 1

ans = 0
for i in range(100):
    for j in range(100):
        if (P[i][j]):
            ans += 1
print(ans)
