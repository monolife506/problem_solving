def dfs(x, y, N, board, estate):

    global cnt  # 전역 변수 사용
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    cnt += 1
    board[y][x] = 0
    for i in range(4):
        next_x = x + dx[i]
        next_y = y + dy[i]
        if (next_x < 0 or next_x >= N or next_y < 0 or next_y >= N):
            continue
        if (board[next_y][next_x] == 1):
            dfs(next_x, next_y, N, board, estate)


N = int(input())
board = [list(map(int, input())) for i in range(N)]

estate = []
for i in range(N):
    for j in range(N):
        cnt = 0
        if (board[i][j] == 1):
            dfs(j, i, N, board, estate)
            estate.append(cnt)

estate.sort()
print(len(estate))
for num in estate:
    print(num)
