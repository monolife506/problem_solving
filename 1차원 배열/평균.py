N = int(input()); total = 0
scores = list(map(int, input().split()))
M = sorted(scores)[-1]
for item in scores :
    item = item / M * 100
    total += item
print("{0:0.6f}".format(total / N))
