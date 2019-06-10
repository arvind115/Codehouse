#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        ll N,f[1000004]={0},x; /// 1000004
        cin>>N;
        ll e=0,o=0,tempe=0,tempo=0;
        for(int i=0;i<N;i++){
            cin>>x;
            f[x]+=1;
            if(x%2==0)e+=1;
            else o+=1;
        }
        e=(e*(e-1))/2; /// total pairs of even nos
        o=(o*(o-1))/2; /// total pairs of odd nos
        for(int i=1;i<=1000002;i++){ /// 1000002
            if(f[i]>0){ /// no is present in the array
                if(i%2==0){  /// even no
                    e-=(f[i]*(f[i]-1))/2; ///remove the 'self' pairs
                    if(f[i^2]>0)
                        tempe+=f[i]*f[i^2];
                }
                else{  /// odd no
                    o-=(f[i]*(f[i]-1))/2; /// remove the 'self' pairs
                    if(f[i^2]>0)
                        tempo+=f[i]*f[i^2];
                 }
            }
        }
        ll ans=(e-tempe/2)+(o-tempo/2);
        cout<<ans<<"\n";
    }
    return 0;
}
