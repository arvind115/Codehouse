///https://www.codechef.com/OCT18B/problems/MINDSUM
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int s(ll n,int c,ll B[]){
    if(n<=9){
        if(c<B[n])
            B[n]=c;
        return n;
    }
    else{
        int t=0;
        while(n>0){
            t+=n%10;
            n/=10;
        } return t;
    }
}
void f(ll N,ll D,int c,ll B[]){
    if(c>15)return;
    f(s(N,c,B),D,c+1,B); ///to the left side.
    f(N+D,D,c+1,B); ///to the right side.
}
int main(){
    int t;cin>>t;
    while(t--){
        ll B[300];
        for(int i=0;i<300;i++)
            B[i]=LONG_LONG_MAX;
        ll N,D;
        cin>>N>>D;
        f(N,D,0,B);
        for(int i=1;i<=100;i++){
            if(B[i]!=LONG_LONG_MAX){
                cout<<i<<" "<<B[i]<<"\n";
                break;
            }
        }
    }
	return 0;
}
