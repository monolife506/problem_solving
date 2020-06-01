# 파이썬은 시간 초과 방지를 위해 약간 다른 풀이를 요구한다.
# board[i] == i번째 행에 퀸이 존재하는 열이라 정의하자.
# PyPy3로 제출한다.


def nQueen(r):
    global N, board

    if (r == N):
        return 1

    total = 0
    for c in range(1, N + 1):
        flag = True
        for i in range(1, r + 1):
            if (board[i] == c or abs((r + 1) - i) == abs(c - board[i])):
                flag = False
                break

        if (flag):
            board[r + 1] = c
            total += nQueen(r + 1)

    return total


N = int(input())
board = [0 for i in range(N + 1)]
print(nQueen(0))
