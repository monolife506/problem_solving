from collections import deque


def bfs(N, M, maze, visited):

    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    Q = deque()
    Q.appendleft([0, 0])
    visited[0][0] = 1

    while (Q):
        cur = Q.pop()
        if (cur == [N - 1, M - 1]):
            return

        for i in range(4):
            y = cur[0] + dy[i]
            x = cur[1] + dx[i]

            if (x >= M or x < 0):
                continue
            if (y >= N or y < 0):
                continue
            if (visited[y][x] == -1 and maze[y][x] == '1'):
                Q.appendleft([y, x])
                visited[y][x] = visited[cur[0]][cur[1]] + 1


N, M = map(int, input().split())
maze = [list(input()) for i in range(N)]
visited = [[-1 for j in range(M)] for i in range(N)]

bfs(N, M, maze, visited)
print(visited[N - 1][M - 1])
