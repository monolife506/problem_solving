W, I0, T = map(int, input().split())
D, I, A = map(int, input().split())

# 기초 대사량 변화 X
W1 = W
death1 = False
for d in range(D):
    diff = I - (I0 + A)
    W1 += diff
    if (W1 <= 0):
        death1 = True
        break

# 기초 대사량 변화 O
W2 = W
I2 = I0
death2 = False
for d in range(D):
    diff = I - (I2 + A)
    W2 += diff
    if (abs(diff) > T):
        I2 += diff // 2
    if (W2 <= 0 or I2 <= 0):
        death2 = True
        break
yoyo = ((I0 - I2) > 0)

if death1:
    print("Danger Diet")
else:
    print(W1, I0)

if death2:
    print("Danger Diet")
else:
    print(W2, I2, end=' ')
    print("YOYO" if yoyo else "NO")
