A, B = map(int, input().split())
C = int(input())
minute = ((A * 60 + B) + C) % 1440
print(minute // 60, minute % 60)
