import sys
input = sys.stdin.readline

n = int(input())
nums_array = list(map(int, input().split()))
nums_array.sort()

# query
m = int(input())
queries = list(map(int, input().split()))

# 찾는 숫자 시작점 찾기
def lower (arr, target):
    start_ptr, end_ptr = 0, len(arr)
    while start_ptr < end_ptr:
        mid = (start_ptr + end_ptr) // 2
        if arr[mid] < target:
            start_ptr = mid + 1
        else:
            end_ptr = mid
            
    return start_ptr

# 찾는 숫자의 다음 인덱스 찾기
def upper (arr, target):
    start_ptr, end_ptr = 0, len(arr)
    while start_ptr < end_ptr:
        mid = (start_ptr + end_ptr) // 2
        if arr[mid] <= target:
            start_ptr = mid + 1
        else:
            end_ptr = mid
    return start_ptr

for i in range(m):
    
    print(upper(nums_array, queries[i]) - lower(nums_array, queries[i]))

"""


"""
