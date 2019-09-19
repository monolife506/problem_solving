N = int(input())
coordinates = list()
for i in range(N) :
    x, y = map(int, input().split())
    coordinates.append((x, y))
coordinates.sort()
for crdnt in coordinates :
    print(crdnt[0], crdnt[1])