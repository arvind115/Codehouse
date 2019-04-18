#include <bits/stdc++.h>
#include<limits>
using namespace std;
int main(void) {
	int n,m; ///vertices, edges
	cin>>n>>m;
	vector<int> adj[n+2];
	for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	return 0;
}

