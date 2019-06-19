#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int fillright(int a[],int i,int n){
    int ans = 0;
    int small = a[i+1],large = a[i+1];
    if( a[i] > a[i+1]){
        int j = i+1;
        for(j=i+1; j<n; j++){
            small = min(small,a[j]);
            large = max(large,a[j]);
            if( a[j] >= a[i])
                break;
        }
        if( large > small && j < n ){
            int limit = min(a[i],large);
            for(int k=i+1; k < j; k++){
                ans+=(limit-a[k]);
                a[k] = limit;
            }
        }
    }
    return ans;
}
int fillleft(int a[], int i, int n){
    int ans = 0;
    int small = a[i-1],large = a[i-1];
    if( a[i] > a[i-1]){
        int j = i-1;
        for(j=i-1; j>=0; j--){
            small = min(small,a[j]);
            large = max(large,a[j]);
            if( a[j] >= a[i])
                break;
        }
        if( large > small && j >=0){
            int limit = min(a[i],large);
            for(int k=i-1; k>j; k--){
                ans+=(limit-a[k]);
                a[k] = limit;
            }
        }
    }
    return ans;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n;  i++)
            cin >>a[i];
        int ans = 0;
        if( n <= 2){cout<<0<<endl; return 0;}
        for(int i=0; i<n; i++){
            if( i == 0 )
                ans+=fillright(a,i,n);
            else if( i == n-1 )
                ans+=fillleft(a,i,n);
            else{
                ans += fillright(a,i,n);
                ans += fillleft(a,i,n);
            }
        }
        cout << ans << endl;
    }
	return 0;
}

/*
1
10
1 1 5 2 7 6 1 4 2 3
///answer is 7
*/
