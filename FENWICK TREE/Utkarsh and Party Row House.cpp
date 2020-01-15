///https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/utkarsh-and-party-row-house-february-easy/?utm_source=header&utm_medium=search&utm_campaign=he-search
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int type,K,L,R,S,N,Q;
ll bit[100004],bitmul[100004];
int a[100004];
void update(ll *bit, int i, int val){
    for(; i <= N; i += i&-i)
        bit[i] += val;
}
ll qry(ll *bit, int i){
    ll sum = 0;
    for(; i > 0 ; i -= i&-i)
        sum += bit[i];
    return sum;
}
ll rangeqry(ll *bit,int l, int r){
    return qry(bit,r) - qry(bit,l-1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        cin >> a[i];
        update(bit,i,a[i]);
        update(bitmul,i,a[i]*i);
    }
    while( Q-- ){
        cin >> type;
        if( type == 1){
            cin >> K >> L >> R;
            ll ans = 0;
            if( K <= L)
                ans = rangeqry(bitmul,L,R) - rangeqry(bit,L,R)*K;
            else if( K >=R )
                ans = rangeqry(bit,L,R)*K - rangeqry(bitmul,L,R);
            else if( K <= R ){
                ans += rangeqry(bit,L,K-1)*K - rangeqry(bitmul,L,K-1);
                ans += rangeqry(bitmul,K+1,R) - rangeqry(bit,K+1,R)*K;
            }
            cout << ans << endl;
        }
        else{
            cin >> K >> S;
            update(bit,K,S);
            update(bitmul,K,S*K);
        }
    }
    return 0;
}
/*
6 4
1 1 1 1 1 1
1 1 5 6
1 6 1 5
2 1 1
1 6 1 5
*/
