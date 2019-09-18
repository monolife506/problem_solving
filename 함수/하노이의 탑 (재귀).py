def hanoi(from_peg, to_peg, n) :
    if (n == 1) :
        print(from_peg, to_peg)
    else :
        extra_peg = 6 - from_peg - to_peg
        hanoi(from_peg, extra_peg, n - 1)
        hanoi(from_peg, to_peg, 1)
        hanoi(extra_peg, to_peg, n - 1)
N = int(input())
print(2 ** N - 1); hanoi(1, 3, N)