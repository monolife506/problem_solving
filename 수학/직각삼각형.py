T = list(); case = [1, 1, 1]
while(True) :
    case = list(map(int, input().split()))
    if (max(case) == 0) : break
    T.append(case)
for C in T :
    if (max(C) ** 2 == min(C) ** 2 + (sum(C) - max(C) - min(C)) ** 2) : print("right")
    else : print("wrong")
    