///http://codeforces.com/problemset/problem/913/B
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+3];
    for(int i=2; i<=n; i++){
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    bool isspruce=true;
    for(int i=1; i<=n; i++){
        if( v[i].size() > 0 ){///not a leaf node
            int leaves=0;
            for(int j=0; j<v[i].size(); j++){
                if( v[v[i][j]].size() < 1 )
                    leaves++;
                if( leaves >=3 )
                    break;
            }
            if(leaves < 3){
                isspruce=false;
                break;
            }
        }
    }
    if( isspruce )cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
/*
4 1 1 1
8 1 1 1 1 3 3 3
7 1 1 1 2 2 2
*/
