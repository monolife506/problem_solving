C = int(input())
for i in range(C) :
    scorelist = list(map(int, input().split())); total = 0
    for j in range(1, scorelist[0] + 1) :
        total += scorelist[j]
    average = total / scorelist[0]; over = 0
    for j in range(1, scorelist[0] + 1) :
        if (scorelist[j] > average) :
            over += 1
    print("{0:0.3f}%".format(over / scorelist[0] * 100))