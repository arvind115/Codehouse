///http://codeforces.com/problemset/problem/339/D
#include <bits/stdc++.h>
using namespace std;
int merge(int a,int b,int l,int N){
    if( ( N%2==0 && l%2==0) || ( N%2!=0 && l%2!=0 ) )
        return a|b;
    else if( ( N%2!=0 && l%2==0) || ( N%2==0 && l%2!=0) )
        return a^b;
}
void build(int seg[],int a[],int low,int high, int pos,int l,int N){
    if(low==high){
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(seg,a,low,mid,2*pos+1,l+1,N);
    build(seg,a,mid+1,high,2*pos+2,l+1,N);
    seg[pos]=merge(seg[2*pos+1],seg[2*pos+2],l,N);
}
int query(int seg[],int qlow, int qhigh, int low, int high, int pos,int l,int N){
    if( qlow>=low && high <=qhigh) ///totally within the asked range
        return seg[pos];
    /// a|0 = a, a^0 = a
    if( low > high)
            return 0;
    if( low > qhigh || high < qlow )
        return 0;
    int mid = (low+high)/2;
    return merge(query(seg,qlow,qhigh,low,mid,2*pos+1,l+1,N),query(seg,qlow,qhigh,mid+1,high,2*pos+2,l+1,N),l,N);
}
void update(int seg[],int qlow, int qhigh,int low, int high,int val, int pos,int l,int N){///point update
    if( qlow == low && qhigh == high ){
        seg[pos]=val;
        return;
    }
    if( low > high )
        return;
    if( low > qhigh || high < qlow )
        return;
    int mid = (low+high)/2;
    update(seg,qlow,qhigh,low,mid,val,2*pos+1,l+1,N);
    update(seg,qlow,qhigh,mid+1,high,val,2*pos+2,l+1,N);
    seg[pos]=merge(seg[2*pos+1],seg[2*pos+2],l,N);
}
int main() {
	int n,m;
	cin>>n>>m;
	int N=n;
	n=int(pow(2,n));
	int a[n+2];
	for(int i=0; i<n; i++)
	    cin>>a[i];
	int nextPowOf2 = (int)round(pow(2, ceil(log2(n))));
    int size = 2 * nextPowOf2 - 1;
	int seg[size];
	build(seg,a,0,n-1,0,1,N);
	for(int i=0; i<m; i++){
        int p,val;
        cin>>p>>val;
        update(seg,p-1,p-1,0,n-1,val,0,1,N); ///point update
        cout<<query(seg,0,n-1,0,n-1,0,1,N)<<endl;
	}
	return 0;
}
/*
1 1
1 1
1 1
2 4
1 6 3 5
1 4
3 4
1 2
1 2
4
4 2 4 5
ans = 1

    4 2 1
    1 1 1
    1 1 0
    0 1 0

     1
   /   \
  6     7
 / \   /  \
4   6  3   5
*/
