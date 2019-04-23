///http://codeforces.com/contest/189/submission/49834337
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,val[3];
    cin>>n>>val[0]>>val[1]>>val[2];
    sort(val,val+3);
    int a=val[0],b=val[1],c=val[2];
    int dp[n+2]={0};
    c=min(n,c); ///fix the upper bound
    b=min(n,b);
    a=min(n,a);
    dp[a]=dp[b]=dp[c]=1;
    for(int i=a+1;i<=n;i++){
        int temp=0;
        if(i>=c)
            temp=max(max(dp[i-a],dp[i-b]),dp[i-c]);
        else if(i>=b)
            temp=max(dp[i-a],dp[i-b]);
        else
            temp=dp[i-a];
        if(temp>0) ///can be formed
            dp[i]=max(dp[i],temp+1);
        else dp[i]=max(dp[i],0);
    }
    cout<<dp[n]<<"\n";
    return 0;
}
/*
14 2 5 7
*/
