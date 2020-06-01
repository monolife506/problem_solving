def backtrack(cur, total):
    global nums, oper, min_val, max_val, N
    if (cur == N - 1):
        max_val = max(max_val, total)
        min_val = min(min_val, total)
        return

    if (oper[0] > 0):
        oper[0] -= 1
        backtrack(cur + 1, total + nums[cur + 1])
        oper[0] += 1

    if (oper[1] > 0):
        oper[1] -= 1
        backtrack(cur + 1, total - nums[cur + 1])
        oper[1] += 1

    if (oper[2] > 0):
        oper[2] -= 1
        backtrack(cur + 1, total * nums[cur + 1])
        oper[2] += 1

    if (oper[3] > 0):
        oper[3] -= 1

        # Python과 C++의 나눗셈 연산자는 값이 다르다.
        backtrack(cur + 1, int(total / nums[cur + 1]))
        oper[3] += 1


N = int(input())
nums = list(map(int, input().split()))
oper = list(map(int, input().split()))
max_val = -1100
min_val = 100 ** 11

backtrack(0, nums[0])
print(max_val, min_val, sep="\n")
