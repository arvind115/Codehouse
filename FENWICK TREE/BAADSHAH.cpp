///https://www.codechef.com/problems/BAADSHAH
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll bit[100003],s;
int N,M;
void update(int i,int val){
    for(; i <=N; i += i&-i)
        bit[i] += val;
}
ll qry(int i){
    ll sum = 0;
    for(; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}
int found(ll S){
    int low = 1, high = N, pos = 0,mid;
    while( low <= high ){
        mid = (low + high)>>1;
        ll sum = qry(mid);
        if( sum >= S){
            pos = mid;
            high = mid - 1;
        }
        else if( sum < S)
            low = mid + 1;
    }
    if( qry(pos) == S)
        return pos;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    ll a[N+1];
    for(int i = 1; i <=N; i++ ){
        cin >> a[i];
        update(i,a[i]);
    }
    while( M-- ){
        int type; cin >> type;
        if( type == 1){//update
            int ind; ll val;
            cin >> ind >> val;
            ll prev = a[ind];
            if( val > prev ) // 6,10
                update(ind,val-prev);
            else update(ind,-(prev-val));//10,8
            a[ind] = val;
        }
        else{
            ll S; cin >> S;
            int pos = found(S);
            if( pos != 0 )
                cout<<"Found "<< pos << endl;
            else cout << "Not Found\n";
        }
    }
    return 0;
}
