import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * (n+1) # 해당 숫자를 만들 수 있는 최소 연산 수
dp[1] = 0

for i in range(2, n+1):
    dp[i] = dp[i-1] + 1 

    if i % 2 == 0: # 2로 나누어 떨어지면 최소 연산 횟수 비교
        dp[i] = min(dp[i], dp[i // 2] + 1) # 이전 수의 최소 연산 횟수에 1 더한 값과 2로 나눈 수의 연산 횟수에 1 더한 값
    if i % 3 == 0: # 3으로 나누어 떨어지면 최소 연산 횟수 비교
        dp[i] = min(dp[i], dp[i // 3] + 1) # 이전 수의 최소 연산 횟수에 1 더한 값과 3로 나눈 수의 연산 횟수에 1 더한 값

print(dp[n])
