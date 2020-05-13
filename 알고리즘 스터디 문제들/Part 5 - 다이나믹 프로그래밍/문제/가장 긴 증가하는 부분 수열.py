N = int(input())
A = list(map(int, input().split()))  # A[i] = 수열의 i번째 숫자
lenList = [1 for i in range(N)]  # lenList[i] = i번째에서 끝나는 증가하는 부분 수열의 최대 길이
for i in range(N - 1):
    for j in range(i + 1, N):
        if (A[j] > A[i] and lenList[j] <= lenList[i] + 1):
            lenList[j] = lenList[i] + 1
print(max(lenList))
