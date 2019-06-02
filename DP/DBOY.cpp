///https://www.codechef.com/problems/DBOY
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int h[502],dp[1004]={0};
        int n, ma = 0; ///max distance
        cin>>n;
        for(int i = 0; i<n; ++i){
            cin>>h[i];
            h[i] = 2*h[i]; ///actual dist
            ma = max(ma,h[i]);
        }
        for(int i = 0; i < n; ++i){
            int a;cin>>a;
            dp[a] = 1; ///shortest for current 'i'
        }
        for(int i = 1; i <= ma; ++i){
            int temp = 987654321; ///was wierd with INT_MAX
            while(!dp[i]){ ///true when 'i' not in array k like 8 not in 1 4 5 3
                for(int j = 1; j <= (i/2); ++j)
                    temp = min(temp,dp[j]+dp[i-j]);
                dp[i] = temp;
            }
        }
        int ans=0;
        for(int i = 0; i < n; ++i)
            ans+=dp[h[i]];
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
1
2
2
4
1 2 3 4
1 0 0 0
5
1 2 3 4 9
1 4 5 3 10
*/
