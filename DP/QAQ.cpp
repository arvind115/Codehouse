///http://codeforces.com/problemset/problem/894/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.length()+2;
    int pre[n]={0},suf[n]={0};
    for(int i=0;i<s.length();i++){
        if(s[i]=='Q')
            pre[i]=suf[i]=1;
    }
    for(int i=1;i<s.length();i++)
        pre[i]+=pre[i-1];
    for(int i=s.length()-2;i>=0;i--)
        suf[i]+=suf[i+1];
    int ans=0;
    for(int i=1;i<s.length();i++){
        if(s[i]=='A')
            ans+=pre[i-1]*suf[i+1];
    }
    cout<<ans<<"\n";
    return 0;
}
/*
QAQAQYSYIOIWIN
*/