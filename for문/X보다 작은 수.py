N, X = map(int, input().split())
numbers = input().split()
numbers = map(int, numbers)
for i in numbers :
    if (i < X) :
        print(i, end = ' ')