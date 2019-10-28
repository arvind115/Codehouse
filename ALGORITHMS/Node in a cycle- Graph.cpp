/**
A C++ program to find the nodes forming a cycle in an undirected graph
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool vis[400000+2];
vector<int> adj[400000+2];
vector<int> ans;
int cyclicNode = 0;
bool dfs(int s,int parent){
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); i++){
        int child = adj[s][i];
        if( child == parent )
            continue;
        if( vis[child] ){
            cyclicNode = child;
            ans.push_back(s);
            return true;
        }
        if( dfs(child,s) ){
            if( cyclicNode != 0 ){
                ans.push_back(s);
                if( s == cyclicNode )///all cyclic node covered
                    cyclicNode = 0;
            }
            return true;
        }
    }
    return false;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while( t-- ){
        int n,m; cin >> n >> m;
        for(int i=0; i <= n+1; i++)
            adj[i].resize(0);
        for(int i=0; i <= n+n; i++)
            vis[i] = false;
        for(int i = 1; i <= m; i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool f = false;
        for(int i = 1; i <= n; i++){
            if( vis[i] )
                continue;
            if(dfs(i,-1)){
                    f = true;
                    cout << ":)" << endl;
                    cout << ans.size() << endl;
                    for(int x=0; x < ans.size();  x++)
                        cout << ans[x] << " ";
                    cout << endl;
                    break;
            }
        }
        if( !f )cout << ":(" << endl;
    }
    return 0;
}
/*
1
8 8
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 3
*/
