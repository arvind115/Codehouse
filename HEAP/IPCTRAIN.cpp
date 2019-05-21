#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int ll;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll N,D;
        cin>>N>>D;
        vector<pair<ll,ll> > v[D+3];
        for(int i=0;i<N;i++){
            ll d,T,S;
            cin>>d>>T>>S;
            v[d].pb(mp(S,T));
        }
        priority_queue<pair<ll,ll> > pq;
        for(int d=1;d<=D;d++){
            ///push the entries for day 'd' into 'pq'.
            if(v[d].size()){
              ///  cout<<"inserting on day"<<d<<"\n";
                for(int i=0;i<v[d].size();i++)
                    pq.push(mp(v[d][i].first,v[d][i].second));
                ///update the 'pq; for the current day.
            }
            if(pq.empty())continue;
            ll x,y;
            x = pq.top().first; ///sadness
            y = pq.top().second; ///lectures
            pq.pop();
            y-=1;
            if(y>0)
                pq.push(mp(x,y));

        }
        ll ans=0;
        ///cout<<"queue at end\n
        while(!pq.empty()){
            ans+=pq.top().first*pq.top().second;
            pq.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
2 3
2 4 500
1 2 1000
*/
