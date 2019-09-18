M, N = map(int, input().split())
decimals = [True for i in range(N + 1)]
decimals[0] = False; decimals[1] = False
for num, isdecimal in enumerate(decimals) :
    if (isdecimal == False) : continue
    else : 
        multi = 2
        while (num * multi <= N) :
            decimals[num * multi] = False
            multi += 1
for i in range(M, N + 1) :
    if (decimals[i] == True) : print(i)