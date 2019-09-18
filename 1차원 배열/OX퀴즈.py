T = int(input())
for i in range(T) :
    score = 0; target = input()
    targetlist = target.split('X')
    for item in targetlist :
        total = range(1, item.count('O') + 1)
        for j in range(1, item.count('O') + 1) :
            total += j
        score += total
    print(score)

    
