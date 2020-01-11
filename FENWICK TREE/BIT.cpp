#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ans = 0;
int BIT[100004],n,k;
vector<int> adj[100004];
bool vis[100004];
void update(int i, int val){
    for(; i <=n; i += i&-i)
        BIT[i] += val;
}
int query(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += BIT[i];
    return sum;
}
void dfs(int s){
    if( !vis[s]){
        vis[s] = true;
        ans += query(min(n,s+k)) - query(max(0,s-k-1));
        update(s,1);
        for(int i=0; i<adj[s].size(); i++){
            int child = adj[s][i];
            if( !vis[child])
                dfs(child);
        }
        update(s,-1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int s;
    for(int i=1; i<=n-1; i++){
        int par,ch; cin >> par >> ch;
        adj[par].push_back(ch);
        if(i == 1)
            s = par;
    }
    dfs(s);
    cout << ans << endl;
    return 0;
}
/*
6 1
1 2
1 3
3 4
3 5
3 6
*/
