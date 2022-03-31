def han_number(_N) :
    if (_N < 100) :
        return True
    elif (_N == 1000) :
        return False
    elif (int(str(_N)[0]) + int(str(_N)[2]) == 2 * int(str(_N)[1])) :
        return True
    else :
        return False
N = int(input()); count = 0
for i in range(N, 0, -1) :
    if (han_number(i) == True) :
        count += 1
print(count)
