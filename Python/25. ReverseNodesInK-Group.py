from math import gcd
l=[]
dp=[]
n=-1
def solve(index,gcd_):
    global dp
    global l
    global n
    if index==n:
        if gcd_==1:
            return 1
        return 0
    if dp[index][gcd_]==-1:
        dp[index][gcd_]=solve(index+1,gcd_)+solve(index+1,gcd(gcd_,l[index]))
    return dp[index][gcd_]
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    ans=0
    dp=[[-1 for i in range(10001)]for i in range(n+1)]
    for i in range(n):
        ans+=solve(i+1,l[i])
    print(ans)
            
            
    
