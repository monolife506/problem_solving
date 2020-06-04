def backtrack(ans, pre, nums, N, M):
    if (len(ans) == M):
        for num in ans:
            print(num, end=" ")
        print()
        return

    for i in range(pre + 1, N):
        ans.append(nums[i])
        backtrack(ans, i, nums, N, M)
        ans.pop()


N, M = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()
backtrack([], -1, nums, N, M)
