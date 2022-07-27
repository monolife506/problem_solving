from datetime import datetime, timedelta
from sys import stdin

N = int(stdin.readline())

if N == 0:
    print(0)
    exit(0)

c = [None for i in range(N)]

for i in range(N):
    date, time, score = stdin.readline().split()
    t = datetime.strptime(date + " " + time, "%Y/%m/%d %H:%M:%S")
    l = int(score)
    c[i] = (t, l)

p_sum = 0
weighted_p_sum = 0

for i in range(N):
    e = timedelta.total_seconds(c[-1][0] - c[i][0]) / (365 * 86400)
    p = max(0.5 ** e, 0.9 ** (N - (i + 1)))
    p_sum += p
    weighted_p_sum += p * c[i][1]

print(round(weighted_p_sum / p_sum))
