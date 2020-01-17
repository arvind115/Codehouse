///https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-round-numbers/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,q,l,r;
int bit[200004];
ll a[200004];
void update(int i, int val){
    for(; i <= n; i += i&-i)
        bit[i] += val;
}
int qry(int i){
    int sum = 0;
    for(; i > 0 ; i -= i&-i)
        sum += bit[i];
    return sum;
}
bool round(ll n){
    if( n < 0)return false;
    if( n >= 0 && n <= 9 )return true;
    int last = n%10; n/=10;
    int first = -1;
    while( n > 0 ){
        first = n%10;
        n /= 10;
    }
    return last == first;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( round(a[i]) )
            update(i,1);
    }
    while( q-- ){
        int type; cin >> type;
        if( type == 1){
            cin >> l >> r;
            int ans = qry(r) - qry(l-1);
            cout << ans << endl;
        }
        else{
            int i; ll K; cin >> i >> K;
            update(i,round(K) - round(a[i]));
            a[i]=K;
        }
    }
    return 0;
}
