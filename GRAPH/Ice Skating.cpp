///http://codeforces.com/contest/217/problem/A
#include <bits/stdc++.h>
using namespace std;
void dfs(int x[], int y[], bool vis[], int s, int n){
    if( !vis[s] ){
        vis[s] = true;
        for(int i=0; i<n; i++){
            if( !vis[i] && (x[i] == x[s] || y[i] == y[s]))
                dfs( x, y, vis, i, n);
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x[10002],y[1002];
    bool vis[n+3]={false};
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if( !vis[i]){
            ans++;
            dfs( x, y, vis, i, n);
        }
    }
    cout << ans-1 << "\n";
	return 0;
}
/*
8
1 1
4 1
1 6
4 6
10 7
14 7
10 11
14 11
*/
