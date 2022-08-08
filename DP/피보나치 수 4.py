n = int(input())

cache = [0 for i in range(100001)]
cache[0] = 0
cache[1] = 1

for i in range(2, n + 1):
    cache[i] = cache[i - 1] + cache[i - 2]

print(cache[n])
