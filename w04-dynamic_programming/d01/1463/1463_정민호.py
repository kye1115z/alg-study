# 점화식
# 1. (n%3 == 0)
    # -> Fn = min(F(n-1), F(n/3))+1
# 2. (n%2 == 0)
    # -> Fn = min(F(n-1), F(n/2))+1
# else
    # -> Fn = F(n-1)+1

N = int(input())
if N == 1:
    print(0)
else:
    dp = [0 for _ in range(max(4, N+1))]
    dp[2] = dp[3] = 1
    
    for i in range(4, N+1):
        if i%3 == 0:
            dp[i] = min(dp[i-1], dp[i//3])+1
        elif i%2 == 0:
            dp[i] = min(dp[i-1], dp[i//2])+1
        else:
            dp[i] = dp[i-1]+1
    
    print(dp[N])
    