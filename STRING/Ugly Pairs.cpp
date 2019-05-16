#include <bits/stdc++.h>
using namespace std;
bool check( string s){
    bool ok = true;
    for(int i=0; i<s.size()-1; i++)
        ok = ok&( abs(s[i]-s[i+1]) != 1);
    return ok;
}
int main(){
    int t; cin >> t;
    while( t-- ){
        string s; cin >> s;
        string odd = "", even = "";
        for(int i=0;  i<s.size(); i++){
            if( s[i]&1 )
                odd+=s[i];
            else even+=s[i];
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        if( check(even+odd) )
            cout<<even+odd<<endl;
        else if( check(odd+even) )
            cout<<odd+even<<endl;
        else cout<<"No answer\n";
    }
    return 0;
}
/*
4
abcd
gg
codeforces
abaca
*/
