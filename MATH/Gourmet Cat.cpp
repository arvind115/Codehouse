///http://codeforces.com/contest/1154/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int f(int a,int b,int c, int d){
    int ans = 0;
    for(int day = d; ;){
        if( day > 7 )
            day = 1;
        if( day == 1 || day == 4 || day == 7){
            if( a > 0 ){
                a-=1;
                ans+=1;
            }
            else break;
        }
        if( day == 2 || day == 6){
            if( b > 0 ){
                b-=1;
                ans+=1;
            }
            else break;
        }
        if( day == 3 || day == 5){
            if ( c > 0 ){
                c-=1;
                ans+=1;
            }
            else break;
        }
        day+=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int w = min(a/3,min(b/2,c/2));
    int days = w*7;
    a-=w*3;
    b-=w*2;
    c-=w*2;
    int ans=-1;
    for(int i=1; i<=7; i++)
        ans = max(ans, f(a,b,c,i));
    ans+=days;
    cout<<ans<<endl;
    return 0;
}

/*
6
1 4 4 7 4 1

*/