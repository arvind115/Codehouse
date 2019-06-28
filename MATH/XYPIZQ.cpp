///https://www.codechef.com/JAN19A/problems/XYPIZQ
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        ll N,t,x,y,z;
        cin>>N>>t>>x>>y>>z;
        ll Nr,Dr=(2*N+1);
        if(t==1){
            if((x<y&&y<z)||(x>y&&y>z))
                Nr = (Dr-z);
            else if(x==z)
                Nr = x;
        }
        else if(t==2){
            if(x==z)
                Nr = 0;
            else
                Nr = Dr-2*y;
        }
        else if(t==3){
            if((x>y&&y>z)||(x<y&&y<z))
                Nr = (Dr-x);
            else if(x==z)
                Nr = x;
        }
        else if(t==4){
            if(x==z)
                Nr =0;
            else
                Nr = Dr-2*y;
        }
        ll GCD = __gcd(Nr,Dr);
        Nr/=GCD;
        Dr/=GCD;
        cout<<Nr<<" "<<Dr<<"\n";
    }
    return 0;
}

