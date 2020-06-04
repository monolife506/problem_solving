# C++의 로직을 그대로 불러와서 PyPy3로 채점하지 않으면 시간 초과가 발생합니다.
from collections import deque
from sys import stdin

M, N, H = map(int, input().split())
box = [[list(map(int, stdin.readline().split())) for row in range(N)]
       for height in range(H)]

q = deque()
max_day = 1
remain = 0

for i in range(H):
    for j in range(N):
        for k in range(M):
            if (box[i][j][k] == 1):
                q.appendleft([i, j, k])
            elif (box[i][j][k] == 0):
                remain += 1

dx = [0, 0, 0, 0, 1, -1]
dy = [0, 0, 1, -1, 0, 0]
dz = [1, -1, 0, 0, 0, 0]

while (q):
    cur = q.pop()
    for i in range(6):
        z = cur[0] + dz[i]
        y = cur[1] + dy[i]
        x = cur[2] + dx[i]

        if (x < 0 or x >= M):
            continue
        if (y < 0 or y >= N):
            continue
        if (z < 0 or z >= H):
            continue

        if (box[z][y][x] == 0):
            box[z][y][x] = box[cur[0]][cur[1]][cur[2]] + 1
            q.appendleft([z, y, x])

            remain -= 1
            max_day = max(max_day, box[z][y][x])

print(max_day - 1 if (remain == 0) else -1)
