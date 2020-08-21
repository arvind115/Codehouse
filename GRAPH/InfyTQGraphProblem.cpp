#include <bits/stdc++.h>
using namespace std;
vector<int> adj1[10],adj2[10];
int cnm(vector<int> adj[], bool vis[],int s){///count & mark the active nodes in subtree of 's'
    vis[s] = true;
    int cnt = 1;
    for(int i = 0; i < adj[s].size(); i++){
        int child = adj[s][i];
        if( !vis[child])
            cnt += cnm(adj,vis,child);
    }
    return cnt;
}
void dfs(vector<int> adj[], bool vis[], int col[],int s,int p1,int p2){
    if(!vis[s]){
        vis[s] = true;
        for(int i = 0; i < adj[s].size(); i++){
            int child = adj[s][i];
            if(!vis[child]){///unvisited node...
                if( col[child] == col[s]){///same color as parent..
                    if( col[s] == 1 ){///parent & child of color '1'
                        adj1[s].push_back(child);
                        dfs(adj,vis,col,child,child,p2);
                    }
                    else{///parent & child of color '2'
                        adj2[s].push_back(child);
                        dfs(adj,vis,col,child,p1,child);
                    }
                }
                else{///different color than parent..
                    if( col[child] == 1 ){
                        if( p1 != -1 )
                            adj1[p1].push_back(child);
                        dfs(adj,vis,col,child,child,p2);
                    }
                    else{///child of color '2'
                        if( p2 != -1 )
                            adj2[p2].push_back(child);
                        dfs(adj,vis,col,child,p1,child);
                    }
                }
            }
        }
    }
}
int main(){
    int n; cin >> n;
    vector<int> adj[n+2];
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int col[n+2];
    for(int i = 1; i<=n; i++)
        cin >> col[i];
    int p1 = -1, p2 = -1;
    if( col[1] == 1)
        p1 = 1;
    else p2 = 1;
    bool vis2[n+2] = {false};
    dfs(adj,vis2,col,1,p1,p2);
    int q; cin >> q;
    bool vis[n+2] = {false};
    int ans = 0;
    while(q--){
        int x; cin >> x;
        if( !vis[x] ){
            if( col[x] == 1)
                ans += cnm(adj1,vis,x);
            else ans += cnm(adj2,vis,x);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
5
1 3
3 2
2 4
2 5
1 1 2 2 1
2 4 5 1
*/
