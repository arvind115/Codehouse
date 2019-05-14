///http://codeforces.com/problemset/problem/651/A
#include <bits/stdc++.h>
using namespace std;
int f(int A,int B){
    if(A<=0 || B<=0)
        return 0;
    if(A<=1 && B<=1)
        return 0;
    if(A<B){///charge A by 1
        A+=1;
        B-=2;
    }
    else{
        A-=2;
        B+=1;
    }
    return 1+f(A,B);
}
int main(){
    int a,b;cin>>a>>b;
    cout<<f(a,b);
    return 0;
}
/*
3 5
*/