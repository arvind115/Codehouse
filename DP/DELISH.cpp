///https://www.codechef.com/problems/DELISH
 #include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n+2];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll dp_lmin[n+2],dp_lmax[n+2];
        ll dp_rmax[n+2],dp_rmin[n+2];
        dp_lmax[0]=dp_lmin[0]=a[0];
        dp_rmax[n-1]=dp_rmin[n-1]=a[n-1];
        ///contstruct the left min & left max
        for(int i=1;i<n;i++){
            ///if addding current value to previous, increases it, add else start anew.
            if(a[i]+dp_lmin[i-1]<a[i])
                dp_lmin[i]=dp_lmin[i-1]+a[i];
            else
                dp_lmin[i]=a[i]; ///increses the value, so keep the value only.
         ///similar logic for max
         if(dp_lmax[i-1]+a[i]>a[i])
            dp_lmax[i]=dp_lmax[i-1]+a[i];
         else
            dp_lmax[i]=a[i]; ///decreases the sum. so keep it separate
        }
        for(int i=n-2;i>=0;i--){
            if(dp_rmin[i+1]+a[i]<a[i])
                dp_rmin[i]=dp_rmin[i+1]+a[i];
            else
                dp_rmin[i]=a[i];
            if(dp_rmax[i+1]+a[i]>a[i])
                dp_rmax[i]=dp_rmax[i+1]+a[i];
            else
                dp_rmax[i]=a[i];
        }
        ll ans1=-1,ans2=-1,ans=0;
        for(int i=0;i<=n-2;i++){
            ///left min...right max
            ans1=max(ans1,abs(dp_lmin[i]-dp_rmax[i+1]));
            ///left max...right min
            ans2=max(ans2,abs(dp_lmax[i]-dp_rmin[i+1]));
            ans=max(ans1,ans2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
5
1 2 3 4 5
4
-1 -1 1 1
*/
