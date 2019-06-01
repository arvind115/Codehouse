///https://www.codechef.com/problems/FIRESC
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll bfs(vector<int> adj[], bool vis[],int s){
    ll t=0;
    if(vis[s])return 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int s=q.front();q.pop();
        vis[s]=true;
        t+=1;
        for(int i=0;i<adj[s].size();i++){
            if(!vis[adj[s][i]]){
                vis[adj[s][i]]=true;
                q.push(adj[s][i]);
            }
        }
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> adj[n+4];
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool vis[n+3]={false};
        ll ans = 1,comp=0;
        for(int i=1;i<=n;i++){
            ll temp = bfs(adj,vis,i);
            if(temp>0){ ///a new connected component found
                comp+=1;
                ans = ((temp%mod)*(ans%mod))%mod;
            }
        }
        cout<<comp<<" "<<ans<<endl;
    }
    return 0;
}
/*
1
4 0
1 2
2 3
1
9 0
*/
