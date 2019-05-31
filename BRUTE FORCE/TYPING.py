for _ in range(int(input())):
    n=int(input())
    l=['d','f']
    r=['j','k']
    d={}
    answer=0
    for i in range(n):
        s=input()
        #print(s)
        if s in d.keys():
            answer+=d[s]//2
            temp = d[s]/2
        else:
            value=2
            for i in range(1,len(s)):
                if (s[i-1] in l and s[i] in l) or (s[i-1] in r and s[i] in r):
                    value+=4
                else:
                    value+=2
            d[s]=value
            answer+=value
            temp = value
    print(int(answer))
'''
1
5
fdjkd
dfjdk
dfd
fdjkd
kkjjk
'''
