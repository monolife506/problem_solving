def backtrack(ans, nums, N, M):
    if (len(ans) == M):
        for num in ans:
            print(num, end=" ")
        print()
        return

    for i in range(N):
        ans.append(nums[i])
        backtrack(ans, nums, N, M)
        ans.pop()


N, M = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()
backtrack([], nums, N, M)
