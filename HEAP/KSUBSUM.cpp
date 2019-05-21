#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///the concept is to use certain 'points' in prefix sum array, which serve as a potential point for maximum 'k3' sums
    ll t;cin>>t;
    while(t--){
        ll n, k1, k2, k3;
        cin>>n>>k1>>k2>>k3;
        vector<ll> a(n), v;
        vector<pair<ll, ll> > d;
        multiset<ll> s;
        for(ll i=0; i<n; i++){
            cin>>a[i];
            d.pb(mp(a[i],i)); ///keep the indices
        }
        for(ll i=1; i<n; i++)
            d[i].ff=max(d[i].ff, d[i].ff+d[i-1].ff); ///in this case, if d[i].ff is retained, it is one of those 'points'.
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        for(ll i=0; i<n; i++){
            if(s.size()>=k3 && d[i].ff<=*s.begin())///if d[i].ff < s.begin() ,we don't need to add anymore as k3 values must already be there.
                break;
            ll w=0;
            for(int j=d[i].ss; j>=0; j--){
                w+=a[j]; ///we are only adding array elements here,not the prefix sum values
                if(s.size()<k3 || w>*s.begin()){
                    s.insert(w);
                    if(s.size()>k3)///larger value has been inserted, we can remove a smaller one.
                        s.erase(s.begin());
                }
            }
        }
        for(auto it=s.rbegin(); it!=s.rend(); it++)
            v.pb(*it);
        cout<<v[k1-1]<<" "<<v[k2-1]<<" "<<v[k3-1]<<endl;
    }
	return 0;
}
/*
1
5 2 4 6
2 -4 8 -3 5
*/
