word = input(); total = 0; alphabet = "22233344455566677778889999"
for char in word : ascii_word = ord(char) - 65; total += (int(alphabet[ascii_word]) + 1)
print(total)