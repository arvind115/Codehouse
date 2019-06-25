#https://www.codechef.com/COCS2019/problems/ANWCC04
for _ in range(int(input())):
    s=input()
    signs=[]
    A,B,C,D=0,0,0,0
    sign1 = None
    sign2 = None
    for i in range(len(s)):
        if s[i]=='+' or s[i]=='-':
            sign1 = i
            for j in range(i+1,len(s)):
                if s[j]=='+' or s[j]=='-':
                    sign2 = j
                    break
        if sign2 is not None:
                break
    eq = s.index('=')
    A = int(s[:sign1])
    B = int(s[sign1+1:sign2])
    C = int(s[sign2+1:eq])
    D = int(s[eq+1:])
    ans = A
    if s[sign1]=='+':
        ans+= B
    else:
        ans-= B
    if s[sign2]=='-':
        ans-= C
    else :
        ans+= C
    if ans == D:
        print('Valid Equation')
    else:
        print('Invalid Equation')
            
            
            
