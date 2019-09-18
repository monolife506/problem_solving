while (True) :
    try :
        A, B = map(int, input().split())
    except EOFError:
        break
    print(A + B)