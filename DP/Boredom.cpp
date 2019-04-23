///http://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int f[100003]={0},maxe=-1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        f[x]+=1;
        maxe=max(maxe,x);
    }
    int l=max(maxe,n);
    ll dp[l+2]={0};
    dp[1]=f[1];
    for(int i=2;i<=l;i++)
        dp[i]=max(dp[i-1],(ll)dp[i-2]+(ll)i*f[i]);
    cout<<dp[l]<<"\n";
  return 0;
}
/*
10
10 10 10 10 10 10 10 10 10 10
*/
