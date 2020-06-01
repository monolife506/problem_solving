def backtrack(ans, nums, used, N, M):
    if (len(ans) == M):
        for num in ans:
            print(num, end=" ")
        print()
        return

    for i in range(N):
        if (not used[i]):
            used[i] = True
            ans.append(nums[i])
            backtrack(ans, nums, used, N, M)
            used[i] = False
            ans.pop()


N, M = map(int, input().split())
nums = list(map(int, input().split()))
used = [False for i in range(N)]

nums.sort()
backtrack([], nums, used, N, M)
