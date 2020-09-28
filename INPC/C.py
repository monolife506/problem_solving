import math

MAX = 2 ** 64
N = int(input())
diff = MAX - N
print(64 - int(math.log2(diff)))


# 2^63 - 1
# 2^64 - 2

# 2^60 - 1
# 2^61 - 2
# 2^62 - 4
# 2^63 - 8
# 2^64 - 16
