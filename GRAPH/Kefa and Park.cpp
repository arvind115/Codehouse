///http://codeforces.com/problemset/problem/580/C
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int c = 0;
int m;
int a[100003];
void dfs(vector<int> adj[], int s , bool vis[], int cons){
    if ( !vis[s] ){ ///not visited yet
        vis[s] = true;
        if( a[s] == 1)
            cons+=1;
        else cons = 0;
        if( cons <= m ){ ///we can visit further nodes
            if( adj[s].size() == 1 && s != 1){ ///its a leaf node
                c+=1;
                return;
            }
            for( int i=0; i<adj[s].size(); i++) ///internal node
                dfs( adj, adj[s][i], vis, cons);
        }
    }
    else return; ///visited the node
}
int main(){
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    int n;cin>>n>>m;
    vector<int> adj[n+3];
    for( int i=1; i<=n; i++ )
        cin>>a[i];
    for( int i=1; i<n; i++ ){
        int u,v; cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool vis[n+3]={false};
    int cons = 0;
    dfs( adj, 1, vis, cons );
    cout<<c<<endl;
    return 0;
}

/*
4 1
1 1 0 0
1 2
1 3
1 4
7 2
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/