///http://codeforces.com/problemset/problem/919/B
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int ds(int n){
    if(n<=9)return n;
    return n%10+ ds(n/10);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;cin>>k;
    vector<int> v;
    for(int i=20;i<INT_MAX;i+=10){
        int diff = ds(i-1)-10;///difference
        if(ds(i-1-diff)==10)
            v.push_back(i-1-diff);
        if(v.size()>=10000)break;
    }
    cout<<v[k-1];
    return 0;
}
/*
19 27 36...
*/