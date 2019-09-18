N = int(input()); count = 0
numbers = list(map(int, input().split()))
decimals = [True for i in range(999)]
for num, isdecimal in enumerate(decimals) :
    if (isdecimal == False) : continue
    else : 
        multi = 2
        while ((num + 2) * multi <= 1000) :
            decimals[(num + 2) * multi - 2] = False
            multi += 1
for num in numbers :
    if (num < 2) : continue
    if (decimals[num - 2] == False) : continue
    else : count += 1
print(count)
