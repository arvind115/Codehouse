///http://codeforces.com/problemset/problem/474/D
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
	int t,k;
	cin>>t>>k;
	int dp[100003]={0};
	dp[0]=1;
	for(int i=1;i<=100001;++i)
		dp[i]=(dp[i-1]+(i>=k?dp[i-k]:0))%mod;
	for(int i=1;i<=100001;++i)
        dp[i]=(dp[i]+dp[i-1])%mod;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<((dp[y]-dp[x-1]+mod)%mod)<<"\n";
	}
}
