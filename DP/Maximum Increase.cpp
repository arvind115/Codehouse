///http://codeforces.com/problemset/problem/702/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=1;
    int temp=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1])
            temp+=1;
        else temp=1;
        ans=max(ans,temp);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
3 5
*/