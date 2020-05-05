def han(N):
    flag = True
    N_str = str(N)
    for i in range(len(N_str) - 2):
        if (int(N_str[i + 1]) - int(N_str[i]) != int(N_str[i + 2]) - int(N_str[i + 1])):
            flag = False
    return flag


N = int(input())
cnt = 0
for i in range(1, N + 1):
    if (han(i)):
        cnt += 1
print(cnt)
