#include <bits/stdc++.h>
using namespace std;
int merge(int a,int b,int l){
    if( l % 2 == 0)//xor 
        int ans = a^b;
    if( l % 2 == 1)//or
        int ans = a|b;        
    return ans;
}
void build(int seg[],int a[],int low,int high, int pos,int l){
    if(low==high){
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(seg,a,low,mid,2*pos+1,l+1);
    build(seg,a,mid+1,2*pos+2,l+1);
    seg[pos]=merge(seg[2*pos+1],seg[2*pos+2],l);
}
int query(int seg[],int qlow, int qhigh, int low, int high, int pos)
int main() {
	cout<<"GfG!";
	return 0;
}
