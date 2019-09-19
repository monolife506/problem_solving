word = input()
for c in ['c=', 'c-', 'dz=', 'z=', 'd-', 's=', 'lj', 'nj'] : word = word.replace(c, ' ')
total = len(word); print(total)