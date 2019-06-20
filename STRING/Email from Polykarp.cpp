#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string s,s2;
        cin >> s;
        cin >> s2;
        bool yes = true;
        if( s.size() > s2.size()){
            cout<<"NO\n";
            continue;
        }
        for(int i=0,j=0; i<s.size(); i++,j++){
            if( s[i]!=s2[j]){
                yes = false;
                break;
            }
            int f1 = 1;
            for(int k=i+1; k<s.size(); k++){
                if( s[k]!=s[i])break;
                    f1++;
                i = k;
            }
            int f2 = 1;
            int k = j+1;
            for(int k=j+1; k<s2.size(); k++){
                if( s2[k] != s2[j])break;
                f2++;
                j = k;
            }
            if( f2 < f1 || i==s.size()-1 && j!=s2.size()-1){
                yes = false;
                break;
            }
        }
        if( yes )cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
/*
1
aaaa
aaaab
*/
