from math import *
_=int(input(''))
for t in range(_):
    N=int(input(''))
    if N==0:
        print('3')
        continue
    if N==1:
        print('2')
        continue
    temp=log2(N)
    if ceil(temp)==floor(temp): #power of 2
        print('1')
    else:
        first=pow(2,floor(log2(N)))
        sec=N-first
        if ceil(log2(sec))==floor(log2(sec)):
            print('0')
            continue
        Next=pow(2,ceil(temp))
        d=Next-N+1
        d1,d2=10000000000,10000000000
        low=pow(2,floor(log2(sec)))
        high=pow(2,ceil(log2(sec)))
        d1=sec-low
        if high!=first:
            d2=high-sec
        d1=min(d1,d2)
        print(int(min(d1,d)))
