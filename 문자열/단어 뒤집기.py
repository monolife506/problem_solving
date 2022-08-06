T = int(input())
for tc in range(T):
    words = input().split()
    for word in words:
        print(word[::-1], end=' ')
    print()
