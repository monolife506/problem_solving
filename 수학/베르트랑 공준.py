numlist = list(); tmp = 1
while(tmp != 0) :
    tmp = int(input())
    if (tmp != 0) : numlist.append(tmp)
decimals = [True for i in range(max(numlist) * 2 + 1)]
decimals[0] = False; decimals[1] = False
for num, isdecimal in enumerate(decimals) :
    if (isdecimal == False) : continue
    else : 
        multi = 2
        while (num * multi <= len(decimals) - 1) :
            decimals[num * multi] = False; multi += 1
for N in numlist :
    count = 0
    for i in range(N + 1, 2 * N + 1) :
        if (decimals[i] == True) : count += 1
    print(count)