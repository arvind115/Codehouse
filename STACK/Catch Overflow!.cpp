///http://codeforces.com/contest/1175/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long  int ll;
int main() {
    ll limit = 1LL<<32;
    int n; cin >> n;
    stack<ll> s;
    s.push(1);
    ll ans = 0;
    bool over = false;
    while(n--){
        string sr; cin >> sr;
        if( sr == "add"){
            ans+=s.top();
            if( ans >= limit ){
                cout<<"OVERFLOW!!!\n";
                return 0;
            }
        }
        if( sr == "for" ){
            int no ; cin >> no;
            s.push(min(limit,s.top()*no));
            continue;
        }
        if( sr == "end" )
            s.pop();
    }
    cout <<ans<<endl;
    return 0;
}
