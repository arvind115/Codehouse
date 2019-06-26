#http://codeforces.com/contest/1183/problem/C
for _ in range(int(input())):
    k,n,a,b = map(int,input().split())
    if n*b >= k:
        print("-1")
    else:
        x = (k - (n*b))//(a-b)
        x = min(x,n)
        while True:
            y = n-x
            amt = a*x + b*y 
            if amt < k and x+y == n:
                print(x)
                break 
            #else 
            x-=1
