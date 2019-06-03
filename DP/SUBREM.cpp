///https://www.codechef.com/problems/SUBREM
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;

ll dfs(vector<ll> adj[], bool vis[], ll wt[],ll s, ll x){
    ll sum = 0;
    if( vis[s] == false ){ ///unvisited node
        vis[s] = true;
        sum += wt[s];
        for(int i=0; i<adj[s].size(); i++)
            sum+=dfs(adj,vis,wt,adj[s][i],x);
    }
    return max(sum,-x);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while( t-- ){
        int n,x;
        cin >> n >> x;
        vector<ll> adj[n+3];
        ll wt[n+3];
        for(int i=1; i<=n; i++)
            cin >> wt[i];
        for(int i=0; i<n-1; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool vis[n+3]={false};
        ll ans = dfs(adj,vis,wt,1,x);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
3 5
1 -5 -10
1 2
2 3
*/
