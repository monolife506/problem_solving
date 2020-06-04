#11399번 : ATM
N = int(input())
arr = list(map(int, input().split()))
arr.sort()
total = 0
for i, num in enumerate(arr) :
    total += (num * (N - i))
print(total)
