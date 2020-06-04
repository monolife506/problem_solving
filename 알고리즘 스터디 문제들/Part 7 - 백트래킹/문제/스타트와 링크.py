min_diff = 10000


def backtrack(cnt, stats, used, pre, N):
    global min_diff
    if (cnt == N // 2):
        start = 0
        link = 0
        for i in range(N):
            for j in range(N):
                if (used[i] and used[j]):
                    start += stats[i][j]
                elif ((not used[i]) and (not used[j])):
                    link += stats[i][j]
        min_diff = min(min_diff, abs(start - link))
        return

    for i in range(pre + 1, N):
        used[i] = True
        backtrack(cnt + 1, stats, used, i, N)
        used[i] = False


N = int(input())
stats = [0 for i in range(N)]
used = [False for i in range(N)]
for i in range(N):
    stats[i] = list(map(int, input().split()))

backtrack(0, stats, used, 0, N)
print(min_diff)
