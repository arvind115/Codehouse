///http://codeforces.com/problemset/problem/368/B
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int a[n+3];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n+3]={0};
    set<int> s;
    for(int i=n-1;i>=0;i--){
        s.insert(a[i]);
        dp[i]=s.size();
    }
    while(m--){
        int l;cin>>l;
        cout<<dp[l-1]<<"\n";
    }
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