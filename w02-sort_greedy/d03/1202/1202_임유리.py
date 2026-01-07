# 보석도둑
# 제일 작은 가방부터, 가벼운 보석을 차례로 넣어보자

import sys

input = sys.stdin.readline

n, k = map(int, input().split())
gems = [[0] * (n) for _ in range(n)]
for i in range(n):
    m, v = map(int, input().split())
    gems[i] = [m, v]
# 가벼운 순서대로 먼저 정렬, 비싼 순서대로 나중정렬
gems = sorted(gems, key=lambda x: (x[0], -x[1]))

bags = [0] * (k)
for i in range(k):
    bags[i] = int(input())
bags.sort()
max = max(bags)

for i in range(n):
    if gems[i][0] > max:
        gems[i][0] = -1

result = 0

for i in range(k):
    for j in range(n):
        # 만약 이미 넣은 보석이면 건너뛰기
        if gems[j][0] < 0:
            continue
        if bags[i] >= gems[j][0]:
            gems[j][0] = -1
            break
for i in range(n):
    if gems[i][0] == -1:
        result += gems[i][1]
print(result)
