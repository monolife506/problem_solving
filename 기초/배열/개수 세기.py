N = int(input())
arr = list(map(int, input().split()))
v = int(input())

cnt = 0
for num in arr:
    if num == v:
        cnt += 1

print(cnt)
