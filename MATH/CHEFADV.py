for _ in range(int(input())):
    N,M,X,Y=map(int,input().split())
    if N==1 and M==1 or N==2 and M==2:
        print('Chefirnemo')
        continue
    if (N-1)%X==0 and (M-1)%Y==0:
        print('Chefirnemo')
    elif N==1 or M==1:
        if N==1: #cannot use ShareChat card
            if (M-1)%Y==0:
                print('Chefirnemo')
            else:
                print('Pofik')
        if M==1: #cannot use ShareChat card
            if (N-1)%X==0:
                print('Chefirnemo')
            else:
                print('Pofik')
    elif (N-2)%X==0 and (M-2)%Y==0:
        print('Chefirnemo')
    elif (N-1)%X==0 and (M-1)%Y!=0:
        print('Pofik')
    elif (M-1)%Y==0 and (N-1)%X!=0:
        print('Pofik')
    elif N%X==0 and M%Y==0 and X!=1 and Y!=1 or X!=2 and Y!=2:
        print('Pofik')
    else:
        print('Pofik')
        
    