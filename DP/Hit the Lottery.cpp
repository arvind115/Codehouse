///http://codeforces.com/problemset/problem/996/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int ans= n/100;
    int left = n%100;
    if(left > 0){
        ans += left/20;
        left = left%20;
        if(left > 0 ){
            ans += left/10;
            left = left%10;
            if(left > 0 ){
                ans += left/5;
                left = left%5;
                if( left > 0 ){
                    ans +=left;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
++-+-
+-+-+

*/