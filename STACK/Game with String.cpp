///http://codeforces.com/problemset/problem/1104/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    int A = 0, B = 0,j=1;
    bool turnA = true;
    stack<char> S;
    S.push( s[0] );
    for(int i=1; i<s.size(); i++){
        if( S.empty()){
            S.push(s[i]);
            continue;
        }
        if( !S.empty() && s[i] != S.top() ){///push & move on
            S.push( s[i] );
            continue;
        }
        if( !S.empty() && s[i] == S.top()){
            S.pop(); ///remove the common char
            if( turnA ){
                A++;
                turnA = false;
            }
            else{
                B++;
                turnA = true;
            }
        }
    }
    if( A > B)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
///abbbbbabba
