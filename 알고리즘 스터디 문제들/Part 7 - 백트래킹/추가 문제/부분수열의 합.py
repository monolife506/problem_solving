def backtrack(cur, total, nums, N, S):
    if (cur == N):
        if (total == S):
            return 1
        else:
            return 0

    cnt = 0
    cnt += backtrack(cur + 1, total, nums, N, S)
    cnt += backtrack(cur + 1, total + nums[cur], nums, N, S)
    return cnt


N, S = map(int, input().split())
nums = list(map(int, input().split()))

if (S == 0):
    print(backtrack(0, 0, nums, N, S) - 1)
else:
    print(backtrack(0, 0, nums, N, S))