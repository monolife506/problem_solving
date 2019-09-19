def func(N) :
    total = 0
    for i in range(len(str(N))) :
        total += int(str(N)[i])
    return N + total
self_number = [0]
self_number *= 10001
for i in range(1, 10001) :
    if (func(i) <= 10000) :
        self_number[func(i)] = 1
for i in range(1, 10001) :
    if (self_number[i] == 0) :
        print(i)