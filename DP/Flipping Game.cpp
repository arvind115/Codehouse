///http://codeforces.com/problemset/problem/313/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int n = s.length();
    int dp[n+2]={0};
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1])
            dp[i+1]=dp[i]+1;
        else dp[i+1]=dp[i];
    }
    ///for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        cout<<dp[r]-dp[l]<<"\n";
    }
    return 0;
}
/*
7
##...##
*/
