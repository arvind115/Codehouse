//https://www.spoj.com/problems/ANDROUND/
#include <bits/stdc++.h>
#include<limits>
using namespace std;
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
void build(int a[],int seg[],int low,int high,int pos){
    if(low==high){
        seg[pos]=a[low];
        return;
    }
    else{
        int mid=(low+high)/2;
        build(a,seg,low,mid,2*pos+1);
        build(a,seg,mid+1,high,2*pos+2);
    }
    seg[pos]=seg[2*pos+1] & seg[2*pos+2];
}
int query(int seg[],int low,int high,int qlow,int qhigh,int pos){
    //cout<<"low="<<low<<" high="<<high<<"\n";
    if(qlow<=low&&qhigh>=high)
        return seg[pos];
    else if(qlow>high||qhigh<low){
        //cout<<"special case\n";
        return INT_MAX;}// std::numeric_limits<int>::min();
    else{
        int mid=(low+high)/2;
        return query(seg,low,mid,qlow,qhigh,2*pos+1) & query(seg,mid+1,high,qlow,qhigh,2*pos+2);
    }
}
int main(void) {
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int size=pow(2,1+ceil(log2(n)))-1;
    int seg[size];
    build(a,seg,0,n-1,0);
    //cout<<query(seg,0,n-1,0,n-1,0)<<"\n";
    for(int i=0;i<n;i++){
        int leftrange=INT_MAX,rightrange=INT_MAX;
        if(i>=k)  //leftrange
            leftrange=query(seg,0,n-1,i-k,i-1,0);
        else{
            leftrange=query(seg,0,n-1,0,i-1,0);
            if((k-i)>=n)leftrange=leftrange&query(seg,0,n-1,0,n-1,0);
            int rem=(k-i)%n;
            leftrange=leftrange&query(seg,0,n-1,n-rem,n-1,0);
        }
        if((i+k)<=n-1)   //rightrange
            rightrange=query(seg,0,n-1,i+1,i+k,0);
        else{
            rightrange=query(seg,0,n-1,i+1,n-1,0);
            if((k-(n-1-i))>n)rightrange=rightrange&query(seg,0,n-1,0,n-1,0);
            int rem=(k-(n-1-i))%n;
            rightrange=rightrange&query(seg,0,n-1,0,rem-1,0);
        }
        int ans=leftrange&a[i]&rightrange;
        cout<<ans<<" ";
    }cout<<"\n";
    }
    return 0;
}

