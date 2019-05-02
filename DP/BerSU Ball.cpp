///http://codeforces.com/problemset/problem/489/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    multiset<int> s,s2;
    int n;cin>>n;
    while(n--){
        int i;cin>>i;
        s.insert(i);
    }
    cin>>n;
    while(n--){
        int i;cin>>i;
        s2.insert(i);
    }
    int ans=0;
    while(!s.empty()){
        int b = *(s.begin());
        s.erase(s.begin());
        if(s2.find(b-1)!=s2.end()){
            ans+=1;
            s2.erase(s2.find(b-1));
        }
        else if(s2.find(b)!=s2.end()){
            ans+=1;
            s2.erase(s2.find(b));
        }
        else if(s2.find(b+1)!=s2.end()){
            ans+=1;
            s2.erase(s2.find(b+1));
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/*
*/
