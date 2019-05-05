///http://codeforces.com/problemset/problem/363/B
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    int a[n+2];
    a[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
        a[i]+=a[i-1];
    int ind=1,sum=INT_MAX;
    for(int i=k;i<=n;i++){
        if(a[i]-a[i-k]<sum){
            sum=a[i]-a[i-k];
            ind=i-k+1;
        }
    }
    cout<<ind<<"\n";
    return 0;
}
/*
*/