A = 0; B = 1; N = int(input())
for i in range(N) :
    if (i % 2 == 1) : A += B
    else : B += A
print(B if N % 2 == 1 else A)