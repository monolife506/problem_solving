import sys
numbers = []
for i in range(9) :
    numbers.append(int(sys.stdin.readline()))
print(sorted(numbers)[8], '\n' + str(numbers.index(sorted(numbers)[8]) + 1))

