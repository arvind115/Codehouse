///https://www.codechef.com/problems/SUBREM
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        string s;
        cin >> s;
        if( s.length() == 1){
            cout<<s<<endl;
            continue;
        }
        bool noans = false;
        vector<char> v,v2;
        v.push_back(s[0]);
        for(int i=1; i<s.length(); i++){
            int diff = abs(s[i]- v[v.size()-1]);
            if( diff != 1){
                v.push_back(s[i]);
                continue;
            }
            else{
                if( v2.size() < 1){
                    v2.push_back(s[i]);
                    continue;
                }
                diff = abs(s[i] - v2[v2.size()-1]);
                if( diff != 1){
                    v2.push_back(s[i]);
                    continue;
                }
                else{
                    noans = true;
                    break;
                }
            }
        }
        if( noans )cout<<"No answer\n";
        else{
            int diff = abs(v[v.size()-1]-v2[0]);
            if( diff == 1){
                cout<<"No answer\n";
                continue;
            }
            for(int i=0; i<v.size(); i++)
                cout<<v[i];
            for(int i=0; i<v2.size(); i++)
                cout<<v2[i];
            cout<<"\n";
        }
    }
    return 0;
}
/*
3
abcd
gg
codeforces
*/
