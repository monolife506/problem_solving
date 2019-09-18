def hanoi(pegs) :
    print(2 ** len(pegs) - 1)
    for i in range(1, 2 ** len(pegs)) :
        current_bin = str(format(i, 'b'))
        current_peg = len(current_bin) - current_bin.index('1') - 1
        if ((current_peg + 1) // 2 == 1) :
            if (pegs[current_peg] == 1) :
                pegs[current_peg] = 3; print(1, 3)
            else :
                pegs[current_peg] -= 1
                print(pegs[current_peg] + 1, pegs[current_peg])
        else :
            if (pegs[current_peg] == 3) :
                pegs[current_peg] = 1; print(3, 1)
            else :
                pegs[current_peg] += 1
                print(pegs[current_peg] - 1, pegs[current_peg])
N = int(input())
_pegs = [1] * N
hanoi(_pegs)