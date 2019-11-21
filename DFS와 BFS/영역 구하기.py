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
            stack.append((X, Y))
            paper[Y][X] = 1
            empty_size = 1
            while (stack):
                isDeadEnd = True
                for i in range(4):
                    x_now = stack[-1][0] + dx[i]
                    y_now = stack[-1][1] + dy[i]
                    if ((x_now >= N) or (x_now < 0) or (y_now >= M) or (y_now < 0)):
                        if (isDeadEnd == True and i == 3):
                            stack.pop()
                        else:
                            continue
                    if (paper[y_now][x_now] == 0):
                        isDeadEnd = False
                        stack.append((x_now, y_now))
                        paper[y_now][x_now] = 1
                        empty_size += 1
                    elif (i == 3 and isDeadEnd == True):
                        stack.pop()
            empty.append(empty_size)

print(len(empty))
for item in empty:
    print(item, end=' ')
