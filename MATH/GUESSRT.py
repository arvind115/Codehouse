#https://www.codechef.com/FEB19A/problems/GUESSRT
from math import gcd,ceil
MOD=1000000007
def MI(x,y) :
    if gcd(x,y)!=1:
        return -1
    else:
        return pow(x,y-2,y)
for t in range(int(input())):
    INPUT=list(map(int,input().split()))
    N=INPUT[0]
    '''the no of boxes'''
    K=INPUT[1]
    '''no of removable boxes'''
    M=INPUT[2]
    '''no of turns allowed'''
    if(M==1):
        '''only 1 turn allowed '''
        ans=MI(N,MOD)
        print(ans)
        continue
    elif(N%K==0):
        '''basically no guess turn occurs'''
        ans=0
        print(ans)
        continue
    else:
        if(N==1):
            '''only 1 box'''
            print(MI(1,MOD))
            continue
        if(N>K and N%K==0):
            '''case like 20 10 2'''
            M-=1
            N=K
        elif(N>K):
            '''case like 20 9 2'''
            M-=1
            N%=K
        '''cases like 3 20 3'''
        oldM=M
        '''keep old value of M to check for odd-even case'''
        M=ceil(M/2)
        '''actual power of N in last denominator'''
        NR=(pow(N,M,MOD)-pow(N-1,M,MOD))%MOD
        '''sum of numerators except the last term'''
        DR=pow(N,M,MOD)
        '''denominator of last term'''
        if(oldM%2==0):
            DR=(pow(N,M,MOD)*(N+K)%MOD)%MOD
            '''the last denominator in even case'''
            lastNR=pow(N-1,M,MOD)
            '''the last numerator'''
            NR=((NR%MOD*(N+K)%MOD)%MOD+lastNR%MOD)%MOD
            '''reducing to the P/Q form'''
        GCD=gcd(NR,DR)
        DR=DR//GCD
        NR=NR//GCD
        ans=(NR%MOD*MI(DR,MOD)%MOD)%MOD
        print(ans)
