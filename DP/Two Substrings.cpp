///http://codeforces.com/problemset/problem/550/A
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    vector<int> AB,BA;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A' && i+1<s.length() && s[i+1]=='B')
            AB.push_back(i);
        if(s[i]=='B' && i+1<s.length() && s[i+1]=='A')
            BA.push_back(i);
    }
    sort(AB.begin(),AB.end());
    sort(BA.begin(),BA.end());
    if(AB.size()>0 && BA.size()>0){
        int d = abs(AB[0]-BA[BA.size()-1]);
        int d1 = abs(BA[0]-AB[AB.size()-1]);
        if(d>=2 || d1>=2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
    return 0;
}
/*
ABAXXXAB
ABBA
*/