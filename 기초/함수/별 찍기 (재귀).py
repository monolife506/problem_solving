def ster(n, line) :
    if (n == 3) :
        if (line % 3 == 2) : print("* *", end='')
        else : print("***", end='')
    else :
        linecheck = line % n
        if (linecheck > (n // 3) and linecheck <= (2 * (n // 3))) :
            ster(n // 3, line)
            print(' ' * (n // 3), end='')
            ster(n // 3, line)
        else :
            for i in range(3) : ster(n // 3, line)
N = int(input())
for i in range(1, N + 1) :
    ster(N, i); print('')

