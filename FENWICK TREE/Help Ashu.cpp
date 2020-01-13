///https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
#include<bits/stdc++.h>
using namespace std;
int BITe[100002], BITo[100002], a[100002];
int n;
void updE(int i,int val){
    for(; i <= n; i += i&-i)
        BITe[i] += val;
}
void updO(int i, int val){
    for(; i <= n; i += i&-i)
        BITo[i] += val;
}
int qE(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += BITe[i];
    return sum;
}
int qO(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += BITo[i];
    return sum;
}
int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        if( a[i]%2 == 0 )
            updE(i,1);
        else updO(i,1);
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if( t == 0){//upd
            int ind, val;
            cin >> ind >> val;
            if( a[ind]%2 == 0 && val%2 == 1){
                updE(ind,-1);
                updO(ind,1);
            }
            else if( a[ind]%2 == 1 && val%2 == 0){
                updO(ind,-1);
                updE(ind,1);
            }
            a[ind] = val;
        }
        else if( t == 1 ){//eve count
            int L,R; cin >> L >> R;
            int eves = qE(R) - qE(L-1);
            cout << eves << endl;
        }
        else if( t == 2 ){
            int L,R; cin >> L >> R;
            int odds = qO(R) - qO(L-1);
            cout << odds << endl;
        }
    }
    return 0;
}