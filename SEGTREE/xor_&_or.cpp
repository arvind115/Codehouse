#include <bits/stdc++.h>
using namespace std;
int merge(int a,int b,int l){
    int ans;
    if( l % 2 == 0 )/// XOR 
     ans = a^b;
    else ans = a|b; //OR
    return ans;
}
void build(int seg[],int a[],int low,int high, int pos,int l){
    if(low==high){
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(seg,a,low,mid,2*pos+1,l+1);
    build(seg,a,mid+1,high,2*pos+2,l+1);
    seg[pos]=merge(seg[2*pos+1],seg[2*pos+2],l);
}
int query(int seg[],int qlow, int qhigh, int low, int high, int pos,int l){
    if( qlow>=low && high <=qhigh) ///totally within the asked range
        return seg[pos];
    /// a|0 = a, a^0 = a
    if( low > high)
            return 0;
    if( low > qhigh || high < qlow )
        return 0;
    int mid = (low+high)/2;
    return merge(query(seg,qlow,qhigh,low,mid,2*pos+1,l+1),query(seg,qlow,qhigh,mid+1,high,2*pos+2,l+1),l);
}
void update(int seg[],int qlow, int qhigh,int low, int high,int val, int pos){//point update
    if( qlow == low && qhigh == high ){
        seg[pos]=val;
        return;
    }
    if( low > high )
        return;
    if( low > qhigh || high < qlow )
        return;
    int mid = (low+high)/2;
    update(seg,qlow,qhigh,low,mid,val,2*pos+1);
    update(seg,qlow,qhigh,mid+1,high,val,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
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
	build(seg,a,0,n-1,0,1);
	cout<<query(seg,0,n-1,0,n-1,0,1)<<endl;
//	update(seg,0,0,0,n-1,4,0);
//	cout<<query(seg,0,n-1,0,n-1,0)<<endl;
	return 0;
}
