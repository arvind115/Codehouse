///http://codeforces.com/contest/580/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n+2],ans=1;
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1])
            dp[i]=1;
        else
            dp[i]=dp[i-1]+1;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
	return 0;
}
