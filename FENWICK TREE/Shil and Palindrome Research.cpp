///https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/submissions/
#include<bits/stdc++.h>
using namespace std;
int bit[27][100003],n,q;
string s,alpha = "abcdefghijklmnopqrstuvwxyz";
void update(int i,int val, int row){
    for(; i <=n; i += i&-i)
        bit[row][i] += val;
}
int qry(int i, int row){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += bit[row][i];
    return sum;
}
bool rangeqry(int L,int R){
    int oddc = 0;
    for(int i = 0; i<26; i++){
        int f = qry(R,alpha[i]-'a') - qry(L-1,alpha[i]-'a');
        if( f%2 == 1)
            oddc +=1;
    }
    return oddc <=1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    cin >> s;
    for(int i=0; i<s.size(); i++)
        update(i+1,1,s[i]-'a');
    while( q-- ){
        int type; cin >> type;
        if( type == 1 ){//update
            int L; char x;
            cin >> L >> x;
            update(L,-1,s[L-1]-'a');
            update(L,1,x-'a') ;
            s[L-1]=x;
        }
        else{
            int L,R; cin >> L >> R;
            if( rangeqry(L,R) ) cout <<"yes" << endl;
            else cout <<  "no \n";
        }
    }
}
