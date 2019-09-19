N = int(input()); words = list(); count = 0
alpha = [chr(i) for i in range(97, 123)]
for i in range(N) : words.append(input())
for w in words :
    for c in alpha :
        if (w[w.find(c):w.rfind(c)] != (c * (w.rfind(c) - w.find(c)))) : break
        elif (c == 'z') : count += 1
print(count)

