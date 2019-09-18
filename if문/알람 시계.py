H, M = input().split()
H = int(H); M = int(M)
if (M >= 45) :
    print(H, M - 45)
elif (H >= 1) :
    print(H - 1, M + 15)
else :
    print(23, M + 15)