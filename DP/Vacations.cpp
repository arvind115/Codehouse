///http://codeforces.com/problemset/problem/698/A
#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
using namespace std;
int main(){
	int n;cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int d[n+2][3];
	for(int i=0;i<=n;i++){
		for(int j=0;j<3;j++)
			d[i][j]=0;
    }
	if(a[0]==1||a[0]==3)d[0][1]=1;
	if(a[0]==2||a[0]==3)d[0][2]=1;
    for(int i=1;i<n;i++){
		d[i][0]=max(max(d[i-1][0],d[i-1][1]),d[i-1][2]); ///max of the previous day
		if(a[i]==1 || a[i]==3)///contest day
			d[i][1]=max(d[i-1][0]+1,d[i-1][2]+1);
		if(a[i]==2 || a[i]==3) ///gym day
			d[i][2]=max(d[i-1][0]+1,d[i-1][1]+1);
    }
    int mx = max(max(d[n-1][0],d[n-1][1]),d[n-1][2]);
    cout<<n-mx<<endl;
	return 0;
}