import math
l=[]
for i in range(40):
    l.append(2**i-1)
x=int(input())
#if x is of the form 2^n-1 print 0
if x in l:
    print(0)
else:
    ans=[]
    count = 0
    while True:
        bits = len(bin(x)[2:])
        xorval = 2**bits-1
        x = x^xorval
        count += 1
        ans.append(bits)
        if x in l:
            break
        x +=1
        count += 1
    print(count)
    print(*ans)
