from math import *
_=int(input())
m=1000000007
def power(x,y,A,B):
    res = 1      # Initialize result
    mod=A-B
    if mod==0:
        mod=m
    x = x % mod  # Update x if it is more than or equal to p
    while y > 0:
        if y & 1: # If y is odd, multiply x with result
            res = (res*x) % mod
        y = y>>1  # y must be even now y = y/2
        x = (x*x) % mod
    return res

for test in range(_):
    A,B,N=map(int,input().split())
    #print(A,B,N)
    print(gcd(power(A,N,A,B)+power(B,N,A,B),abs(A-B)))
    

