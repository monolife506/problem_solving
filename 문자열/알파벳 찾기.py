word = input(); alphabet = [chr(i) for i in range(97, 123)]
for char in alphabet :
    print(word.find(char), end=' ')