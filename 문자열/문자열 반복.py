T = int(input())
for i in range(T) :
    R, S = input().split(); R = int(R)
    for char in S :
        print(char * R, end='')
    print('')