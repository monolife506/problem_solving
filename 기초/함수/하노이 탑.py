def hanoi(n, s, d):
    if n == 1:
        print(s, d)
        return

    m = 6 - (s + d)
    hanoi(n - 1, s, m)
    hanoi(1, s, d)
    hanoi(n - 1, m, d)


K = int(input())
print(2 ** K - 1)
if K <= 20:
    hanoi(K, 1, 3)
