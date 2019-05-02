///http://codeforces.com/problemset/problem/489/C
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
void f(int d,int s){/// d digits...s sum
    if(d==1 && s==0){cout<<0;return;}
    vector<int> v(d,0);
    v[0]=1;s-=1;
    int j=d-1;
    while(s>0){
        v[j]+=min(9,s);
        s-=min(9,s);
        j-=1;
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i];
}
void f2(int d,int s){
    vector<int> v(d,9);
    int j=d-1;
    while(s>0){
        v[j]-=min(9,s);
        s-=min(9,s);
        j-=1;
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,s;
    cin>>m>>s;
    if(s>m*9 ||(s==0 && m>=2)){
        cout<<"-1 -1\n";return 0;
    }
    f(m,s);
    cout<<" ";
    f2(m,9*m-s);
    return 0;
}
/*

*/
