#include <bits/stdc++.h>
using namespace std;
void build(int seg[],int a[],int low,int high, int pos){
    if(low==high){
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(seg,a,low,mid,2*pos+1);
    build(seg,a,mid+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int query(int seg[],int qlow, int qhigh, int low, int high, int pos){
    if( qlow>=low && high <=qhigh) ///totally within the asked range
        return seg[pos];
    if( low > high)
        return INT_MAX;
    if( low > qhigh || high < qlow )
        return INT_MAX;
    int mid = (low+high)/2;
    return min(query(seg,qlow,qhigh,low,mid,2*pos+1),query(seg,qlow,qhigh,mid+1,high,2*pos+2));
}
int main() {
	int n;///no of elements in seg tree
	cin>>n;
	int a[n+2];
	for(int i=0; i<n; i++)
	    cin>>a[i];
	int nextPowOf2 = (int)round(pow(2, ceil(log2(n))));
    int size = 2 * nextPowOf2 - 1;
	int seg[size];
	build(seg,a,0,n-1,0);
	cout<<query(seg,0,n-1,0,n-1,0);
	return 0;
}
