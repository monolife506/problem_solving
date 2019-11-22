import sys
N = int(input())
stack = []

for i in range(N):
    prompt = sys.stdin.readline().rstrip()
    try:
        prompt_str, prompt_int = prompt.split()
    except:
        prompt_str = prompt
    if (prompt_str == "push"):
        stack.append(int(prompt_int))
    elif (prompt_str == "pop"):
        if (stack):
            print(stack[-1])
            stack.pop()
        else:
            print(-1)
    elif (prompt_str == "size"):
        print(len(stack))
    elif (prompt_str == "empty"):
        if (stack):
            print(0)
        else:
            print(1)
    elif (prompt_str == "top"):
        if (stack):
            print(stack[-1])
        else:
            print(-1)
