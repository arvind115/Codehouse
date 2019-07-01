#http://codeforces.com/contest/1186/problem/D
from math import ceil,floor
l = []
pos = 0 
neg = 0
N = int(input())
flag = [1]*(N+2)
for _ in range(N):
    x = float(input())
    l.append(int(x))
    if ceil(x) != floor(x): #can be changed 
        if x < 0:
            flag[_] = -1
    else: #cant be changed 
        flag[_] = 2
    if x >=0:
        pos+=l[-1] 
    else:
        neg += -l[-1]
for i in range(N):
    if pos == neg:
        break
    if pos < neg and l[i] >=0 and flag[i] == 1:
        l[i]+=1 
        pos+=1 
        if pos == neg:
            break
    if neg < pos and l[i] < 0 and flag[i] == -1:
        l[i]-=1 
        neg+=1 
        if pos == neg:
            break
 
for i in l:
    print(i)
