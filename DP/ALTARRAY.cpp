///https://www.codechef.com/problems/ALTARAY
#include <iostream>
using namespace std;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n+3];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int dp[n+3]={0};
        for(int i=0;i<n;i++)
            dp[i]=0;
        int sign[2]={1,-1},s=0,j;
        for(int i=0;i<n;i++){
            if(a[i]>0)s=1;
            else s=0;
            int x=1;
            for(j=i+1;j<n;j++){
                if(a[j]*sign[s]<0)
                   break;
                x+=1;
                s=(s+1)%2;
            }
            for(int k=i;k<=j-1;k++)
                dp[k]=x--;
            i=j-1;
        }
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";cout<<"\n";
	}
	return 0;
}
/*
2
5
1 -2 3 -4 -5
7
5 6 -5 3 -5 -3 -5
*/
