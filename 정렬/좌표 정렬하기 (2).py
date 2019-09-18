N = int(input())
coordinates = list()
for i in range(N) :
    x, y = map(int, input().split())
    coordinates.append((y, x))
coordinates.sort()
for crdnt in coordinates :
    print(crdnt[1], crdnt[0])