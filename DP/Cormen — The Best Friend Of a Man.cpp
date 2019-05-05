///http://codeforces.com/problemset/problem/732/B
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]>=k)
            continue;
        int d = k-(a[i]+a[i-1]);
        a[i]+=d;
        ans+=d;
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
*/