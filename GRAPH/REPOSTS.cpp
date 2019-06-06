///http://codeforces.com/problemset/problem/522/A
#include <bits/stdc++.h>
using namespace std;
int level = 0;
void dfs(vector<int> adj[], bool vis[], int s, int l){
    level = max(level, l);
    if( !vis[s] ){
        vis[s] = true;
        for(int i=0; i<adj[s].size(); i++){
            int child = adj[s][i];
            if( !vis[child])
                dfs(adj,vis,child,l+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> adj[n+4];
    map<string,int> m;
    int cnt = 0;
    for(int i=0; i<n; i++){
        string child,s2,parent; cin >> child >> s2 >> parent;
        transform(parent.begin(),parent.end(),parent.begin(),::tolower);
        transform(child.begin(),child.end(),child.begin(),::tolower);
        int P,C;
        if( m.find(parent) == m.end() ){
            ++cnt;
            m[parent] = cnt;
            P = cnt;
        }
        else
            P = m.at(parent);
        if( m.find(child) == m.end() ){
            ++cnt;
            m[child] = cnt;
            C = cnt;
        }
        else
            C = m.at(child);
        adj[P].push_back(C);

    }
    bool vis[n+4]={false};
    dfs(adj,vis,1,1);
    cout << level <<endl;
	return 0;
}
