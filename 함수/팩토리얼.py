def fac(_N) :
    if (_N == 0) :
        return 1
    else :
        answer = 1
        for i in range(1, _N + 1) :
            answer *= i
        return answer
N = int(input())
print(fac(N))