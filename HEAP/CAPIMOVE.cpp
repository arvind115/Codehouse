#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp make_pair
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    /*map<int,int> m;
    m.insert(mp(34,45));
    map<int,int>::iterator it = m.find(34);
    cout<<it->second;*/
    int t;cin>>t;
    while(t--){
        int N;cin>>N;
        int a[N+5];
        map<int,int> m;
        set<int> s;
        for(auto i=1;i<=N;i++){
            cin>>a[i];
            m.insert(mp(a[i],i)); /// value-index pair
            s.insert(a[i]); ///tree of values
        }
        vector<int> adj[N+3]; ///actual tree
        for(auto i=0;i<N-1;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto i=1;i<=N;i++){
            ///remove current 'i' and all its neighbours.
            s.erase(s.find(a[i])); ///remove 'a[i]'
            vector<int> neigh;
            for(int j=0;j<adj[i].size();j++)
                neigh.push_back(adj[i][j]); ///get all the neighbors ...index
            for(int j=0;j<neigh.size();j++)
                s.erase(s.find(a[neigh[j]]));
            set<int>::iterator it = s.end(); --it;
            map<int,int>::iterator it2 = m.find(*it);
            cout<<it2->second<<" ";
            ///re-insert all the removed items.
            s.insert(a[i]);
            for(auto j=0;j<neigh.size();j++)
                s.insert(a[neigh[j]]);
        }
        cout<<"\n";
    }
    return 0;
}
/*
2
6
5 10 15 20 25 30
1 3
2 3
3 4
4 5
4 6
6
5 10 15 20 25 30
1 3
2 3
3 4
4 5
4 6
*/
