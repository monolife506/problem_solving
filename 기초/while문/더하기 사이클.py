def cycle(_N) :
    _N = (((_N % 10) + (_N // 10)) % 10) + ((_N % 10) * 10)
    return _N
firstN = int(input())
if (firstN < 10) :
    firstN *= 10
N = firstN; count = 0
while (N != firstN or count == 0) :
    N = cycle(N)
    count += 1
print(count)


