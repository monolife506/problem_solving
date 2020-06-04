# 1037번 : 약수
N = int(input())
nums = list(map(int, input().split()))
nums.sort()
result = nums[0] * nums[-1]
print(result)