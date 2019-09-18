N = int(input()); members = list()
for i in range(N) :
    age, name = input().split(); age = int(age)
    members.append((age, name))
members.sort(key = lambda member : member[0])
for item in members :
    print(item[0], item[1])