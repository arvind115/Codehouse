///http://codeforces.com/contest/1148/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll a,b,ab;
  cin >> a >> b >> ab;
  ll ans  = 0;
  ab+=min(a,b);
  ll mn = min(a,b);
  a-=mn;
  b-=mn;
  ans+=ab*2;
  ///cout << a <<" "<<b <<" "<<ab<<endl;
  if(ab > 0){
    if( a > 0 ){
        ans+=1;
        a-=1;
    }
  }
   if( b > 0 ){
    ans+=1;
    b-=1;
   }
  cout << ans << "\n";
  return 0;
}