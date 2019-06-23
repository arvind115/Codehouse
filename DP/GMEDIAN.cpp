#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define pb push_back
ll values[999][999];
struct s{
  ll freq;
  ll fsum;
};
ll fac[1002];
ll power(ll x,ll y) {
	ll res = 1;	 // Initialize result
	x = x %mod;
	while (y > 0) {
		if (y & 1)
			res = (res*x) % mod;
		y = y>>1; // y = y/2
		x = (x*x) % mod;
	}
	return res;
}
ll modInverse(ll n){
	return power(n,mod-2);
}
ll ncr(ll n,ll r) {
    if (r==0) // Base case
	    return 1;
	return (fac[n]* modInverse(fac[r]) % mod* modInverse(fac[n-r]) % mod) % mod;
}
int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	fac[0]=1;
	for (ll i=1 ; i<=1000; i++)  ///precalculating all factorials.
	    fac[i] = fac[i-1]*i%mod;
	ll NCR[1005][1005];
	ll I=0;
	for(int i=0;i<=1002;i++){ ///precalculating all possible NCR values.
	    ll J=0;
	    for(int j=0;j<=i/2;j++){
	        ll x=ncr(I,J)%mod;
	        NCR[i][j]=x;
	        NCR[i][i-j]=x;
	        J+=1;
	    }
	    I+=1;
	}
	for(int i=0;i<=998;i++)values[0][i]=1;
	for(int i=0;i<=998;i++)values[i][0]=1;
	for(int i=1;i<=998;i++){
        for(int j=1;j<=998;j++)
            values[i][j]=(values[i][j-1]+values[i-1][j])%mod;
	}
	ll t;cin>>t;
	while(t--){
	    ll N,x;
	    cin>>N;
	    ll f[2002]={0};
	    for(ll i=0;i<N;i++){
	        cin>>x;
	        f[x]+=1;
	    }
	    vector<s> v; ///vector to store freq. of an element and sum_freq of all elements before it. (sorted)
	    v.pb({0,0});
	    for(int i=1;i<=2000;i++){
	        if(f[i]) ///push the frequency into 'v' and update the sum.
	            v.pb({f[i],v[v.size()-1].fsum+f[i]});
	    }
	    ll odd=0,even=0,oddN=N;
	    if(N%2==0)oddN-=1;
	    for(ll i=1;i<=oddN;i+=2)  ///odd-length subsequences
	        odd=(odd+ncr(N,i))%mod;//cout<<"odd="<<odd<<"\n";
	    for(int i=1;i<v.size();i++){  ///even-length subsequences
	        if(v[i].freq>=2){       ///update the 'even'
	            ll n1=v[i-1].fsum; ///smaller than current element
	            ll n2=v[v.size()-1].fsum-v[i].fsum; ///larger than current element
	            ll R=v[i].freq-2;
	            for(ll left=0;left<=v[i].freq-2;left++){
	                for(ll right=R;right>=0;right--)
	                    even=(even+values[n1+left][n2+right])%mod;
	                R-=1;
	            }
	        }
	    }//cout<<"Teven="<<even<<"\n";
	    ll ans=(odd+even)%mod;
	    cout<<ans<<"\n";
	}
	return 0;
}
