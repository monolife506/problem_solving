word = input(); word = word.upper(); alphabet = dict()
for i in range(65, 91) : alphabet[chr(i)] = 0
for char in alphabet.keys() : alphabet[char] = word.count(char)
sorted_alphabet = sorted(alphabet.items(), key=lambda t : t[1], reverse=True)
if (sorted_alphabet[0][1] == sorted_alphabet[1][1]) : print('?')
else : print(sorted_alphabet[0][0])