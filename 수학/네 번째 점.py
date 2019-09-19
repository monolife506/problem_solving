X = [None for i in range(3)]; Y = [None for i in range(3)]
for i in range(3) : X[i], Y[i] = map(int, input().split())
for num in X : 
    if (X.count(num) == 1) : print(num, end=" "); break
for num in Y : 
    if (Y.count(num) == 1) : print(num); break