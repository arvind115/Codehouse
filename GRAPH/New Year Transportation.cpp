///http://codeforces.com/problemset/problem/500/A
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], bool vis[], int s ){
    if( vis[s] )
        return ;
    vis[s] = true;
    for(int i=0; i<adj[s].size(); i++){
        int child = adj[s][i];
        if( !vis[child])
            dfs(adj, vis, child);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, t; cin >> n >> t;
    vector<int> adj[n+3];
    for(int i=1; i<=n-1; i++){
        int x; cin >> x;
        adj[i].push_back(i+x);
    }
    bool vis[n+3]={false};
    dfs(adj, vis, 1);
    if( vis[t] )cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
/*
8 4
1 2 1 2 1 2 1
8 5
1 2 1 2 1 1 1
*/
