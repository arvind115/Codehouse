#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int bfs(vector<int> adj[], int s , bool vis[] ){
    int l = 0;
    queue<int> q;
    q.push(s);
    q.push(NULL);
    while( !q.empty() ){
        int z = q.front(); q.pop();
        if( z == NULL ){
            l+=1;
            ///if the q is not empty, push a NULL
            if( !q.empty() ){
                q.push(NULL);
                continue;
            }
            break; ///q is empty
        }
        vis[z] = true;
        for( int i=0; i<adj[z].size(); i++ )
            q.push( adj[z][i] );
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    int n;cin>>n;
    vector<int> adj[n+3];
    for( int i=1; i<=n; i++ ){
        int u;cin>>u;
        if(u!=-1){ ///has a superior
            adj[i].push_back(u);
        }
    }
    int level=-1;
    bool vis[n+3]={false};
    for( int i=1; i<=n; i++ ){
        if( !vis[i] ){ ///not visited yet
            level = max(level, bfs( adj, i, vis ));
        }
    }
    cout<<level<<endl;
    return 0;
}

/*
6
-1
1
2
1
-1
3
*/