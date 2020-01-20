///https://www.spoj.com/problems/INVCNT/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int bit[10000002],n;
void update(int i,int val,int limit){
    for(; i <=limit; i += i&-i)
        bit[i]+=val;
}
int qry(int i){
    int sum = 0;
    for(; i>0; i-=i&-i)
        sum += bit[i];
    return sum;
}
int main() {
	int t; cin >> t;
	while(t--){
	    ll inv = 0;
	    cin >> n; int a[n],mx = INT_MIN;
	    for(int i = 0; i<n; i++){
	        cin >> a[i];
	        mx = max(mx,a[i]);
	    }
	    for(int i = 0; i<n; i++){
            int x = a[i];
            if( x < mx )
	            inv += (qry(mx) - qry(x));
	        update(x,1,mx);
	    }
	    cout << inv << endl;
        for(int i = 0; i <n; i++)
            update(a[i],-1,mx);
	}
	return 0;
}
