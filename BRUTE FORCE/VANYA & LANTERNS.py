n,m = map(int,input().split())
l=list(map(int,input().split()))
l = sorted(l)
diff = -1
for i in range(1,n):
    if l[i]-l[i-1] > diff:
        diff = l[i]-l[i-1]
ans = max(diff/2,l[0],m-l[-1])
print(ans)
