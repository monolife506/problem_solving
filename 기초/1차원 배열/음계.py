order = list(map(int, input().split()))
if (order == [num for num in range(1, 9)]) :
    print("ascending")
elif (order == [num for num in range(8, 0, -1)]) :
    print("descending")
else :
    print("mixed")