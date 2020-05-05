# 삼각수가 담긴 배열 초기화
N = [1]
idx = 2
while (N[-1] <= 1000):
    N.append(N[-1] + idx)
    idx += 1

T = int(input())
for tc in range(T):
    flag = 0
    K = int(input())
    for i in range(len(N)):
        for j in range(len(N)):
            for k in range(len(N)):
                if (K == N[i] + N[j] + N[k]):
                    flag = 1
    print(flag)


# CPython (백준에서 Python)은 인터프리터가 작동하는 시간 때문에
# 시간 초과가 발생합니다. PyPy3로 바꾸어서 답변을 제출하시면 해결됩니다.
