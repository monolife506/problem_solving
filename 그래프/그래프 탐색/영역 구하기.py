# 2583번 : 영역 구하기
M, N, K = map(int, input().split())
paper = [[0 for i in range(N)] for j in range(M)]

# 색칠된 부분 설정
for i in range(K):
    square = list(map(int, input().split()))
    for j in range(square[1], square[3]):
        for k in range(square[0], square[2]):
            paper[j][k] = 1

# DFS 구현
empty = []
stack = []
dx = (0, 0, 1, -1)
dy = (1, -1, 0, 0)

for Y in range(M):
    for X in range(N):
        if (paper[Y][X] == 0):
            paper[Y][X] = 1
            stack.append((X, Y))
            empty_size = 1
            while (stack):
                for i in range(4):
                    x_now = stack[-1][0] + dx[i]
                    y_now = stack[-1][1] + dy[i]
                    if (x_now >= 0 and x_now < N and y_now >= 0 and y_now < M and paper[y_now][x_now] == 0):
                        stack.append((x_now, y_now))
                        paper[y_now][x_now] = 1
                        empty_size += 1
                        break
                    elif (i == 3):
                        stack.pop()
            empty.append(empty_size)

print(len(empty))
empty.sort()
for item in empty:
    print(item, end=' ')
