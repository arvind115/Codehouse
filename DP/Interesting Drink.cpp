///http://codeforces.com/problemset/problem/706/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    vector<int>::iterator upper;
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        upper = upper_bound(v.begin(),v.end(),x);
        cout<<(upper-v.begin())<<"\n";
    }
    return 0;
}
/*
5
3 6 8 10 11
4
1
10
3
11
*/
