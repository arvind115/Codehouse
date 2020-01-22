///https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/string-query-22/
#include<bits/stdc++.h>
using namespace std;
int bit[26][200003],n,q;
string s;
void update(int row,int i,int val){
    for(; i <=n; i += i&-i)
        bit[row][i] += val;
}
int qry(int row,int i){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += bit[row][i];
    return sum;
}
int indqry(int K, char x){
    int low = 1, high = n,mid,ans;
    while( low <= high ){
        mid = (low + high)/2;
        if( qry(x-'a',mid) >= K){
            ans = mid;
            high = mid-1; ///answer may still be on left side  1 1 0 1 0 0 0 0 1
                                                            ///1 2 3 4 5 6 7 8 9
        }
        else
            low = mid+1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s; n = s.size();
    for(int i = 0; i < s.size(); i++)
        update(s[i]-'a',i+1,1);
    cin >> q;
    while( q-- ){
        int K; char x;
        cin >> K >> x;
        int ind = indqry(K,x);
        s[ind-1] = '*';
        update(x-'a',ind,-1);
    }
    for(int i = 0; i< s.size(); i++){
        if( s[i] == '*')continue;
        cout<<s[i];
    }
    cout << endl;
    return 0;
}
/*
abcdbcaab
5
2 a
1 c
1 d
3 b
2 a
*/
