arr = [int(input()) for i in range(5)]
total = 0
for num in arr:
    total += max(num, 40)

print(total // 5)
