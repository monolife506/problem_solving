flag = [False for i in range(31)]
for i in range(28):
    n = int(input())
    flag[n] = True
for i in range(1, 31):
    if not flag[i]:
        print(i)
