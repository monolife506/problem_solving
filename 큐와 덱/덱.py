# 10866번 : 덱
import sys

deque = []
N = int(sys.stdin.readline())

for i in range(N):
    raw_input = sys.stdin.readline().rstrip()
    try:
        prompt, num = raw_input.split()
        num = int(num)
    except:
        prompt = raw_input

    if (prompt == "push_front"):
        deque.insert(0, num)
    elif (prompt == "push_back"):
        deque.append(num)
    elif (prompt == "pop_front"):
        if (deque):
            print(deque[0])
            del deque[0]
        else:
            print(-1)
    elif (prompt == "pop_back"):
        if (deque):
            print(deque[-1])
            del deque[-1]
        else:
            print(-1)
    elif (prompt == "size"):
        print(len(deque))
    elif (prompt == "empty"):
        if (deque):
            print(0)
        else:
            print(1)
    elif (prompt == "front"):
        if (deque):
            print(deque[0])
        else:
            print(-1)
    elif (prompt == "back"):
        if (deque):
            print(deque[-1])
        else:
            print(-1)
