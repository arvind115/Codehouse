///https://www.geeksforgeeks.org/find-subarray-with-given-sum/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while( t-- ){
	    int n, s; cin  >> n >> s;
	    int a[n+2];
	    for(int i=1; i<=n; i++)
	        cin >> a[i];
	    int pre[n+2]; pre[0] = 0; pre[1] = a[1];
	    for(int i=2; i<=n; i++)
	        pre[i] = pre[i-1]+a[i];
	    int p1 = 1, p2 = 1;
	    bool f = false;
	    while( p2 <=n ){
	       int sum = pre[p2]-pre[p1-1];
	       if( sum == s){
	           f = true;
	           break;
	       }
	       if( sum < s ){
	           p2++;
	           continue;
	       }
	       if( sum > s){
	           p1++;
	           continue;
	       }
	    }
	    if( f )cout<<p1<<" "<<p2<<endl;
	    else cout<<-1<<endl;
	}
	return 0;
}
