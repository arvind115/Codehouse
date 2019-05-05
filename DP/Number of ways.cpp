///http://codeforces.com/problemset/problem/466/C
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll a[n+2],sum=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0){cout<<0;return 0;}
    sum/=3;
    ll suf[n+2]={0};
    ll ss=0; ///suffix sum
    for(int i=n-1;i>=0;i--){
        ss+=a[i];
        if(ss==sum)
            suf[i]=1;
    }
    for(int i=n-2;i>=0;i--)
        suf[i]+=suf[i+1];
    ll ps=0; ///prefix sum
    for(int i=0;i<n-2;i++){
        ps+=a[i];
        if(ps==sum)
            ans+=suf[i+2];
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5
1 2 3 0 3
1 0 1 0 1 0
3 2 2 1 1 0
3
1 2 3
*/