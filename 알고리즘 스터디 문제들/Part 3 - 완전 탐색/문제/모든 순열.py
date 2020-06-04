# 다음 순열 알고리즘은 파이썬에서도 동일하게 적용 가능합니다.
# 여기서는 모든 순열을 셀 때 사용할 수 있는 permutations 함수에 대해 다룹니다.
# 파이썬에서 조합과 순열을 활용하는 itertools 내 두 함수
from itertools import permutations, combinations

N = int(input())
nums = [i for i in range(1, N + 1)]
all_permutations = list(permutations(nums))  # 모든 순열을 사전순으로 튜플 리스트로 저장합니다.

for i in all_permutations:
    for j in i:
        print(j, end=" ")
    print()

# nums에서 2개를 뽑아 만든 모든 순열을 사전순으로 튜플 리스트로 저장합니다.
# all_permutations_two = list(permutations(nums, 2))
# combinations 함수도 사용법은 동일합니다.
