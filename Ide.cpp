#include <bits/stdc++.h>
#include<limits>
using namespace std;
int min(int a,int b){
    if(a<b)return a;
    else return b;
}
void update(int seg[],int lazy[],int value,int low ,int high,int ulow,int uhigh,int pos){
    if(low>high)
        return;
    // check if propagation needs to be done
    if(lazy[pos]!=0){
        seg[pos]+=lazy[pos];
        if(low!=high){//not a leaf node...so propagate 'down'
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //no overlap...leave the node
    if(low>uhigh||high<ulow)
        return;
        
    //total overlap
    if(ulow<=low&&uhigh>=high){
        //update the segtree node now
        seg[pos]+=value;
        if(low!=high){
            lazy[2*pos+1]+=value;
            lazy[2*pos+2]+=value;
        }
        //updation done... leave the node
        return ;
    }
    //control arrives here only in case of PARTIAL overlap
    int mid=(low+high)/2;
    // traverse to the LEFT first
    update(seg,lazy,value,low,mid,ulow,uhigh,2*pos+1);
    // traverse to the RIGHT then
    update(seg,lazy,value,mid+1,high,ulow,uhigh,2*pos+2);
    //updation done... now 'update of MIN' value to be done
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
void build(int a[],int seg[],int low,int high,int pos){
    if(low==high){
        // at leaf node of SEGTREE
        seg[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(a,seg,low,mid,2*pos+1);
    build(a,seg,mid+1,high,2*pos+2);
    // min of two children at their parent
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}

int query(int seg[],int lazy[],int low,int high,int qlow,int qhigh,int pos){
    //if(low>high)return;
    //check if 'propagation' needs to be done
    if(lazy[pos]!=0){
        seg[pos]+=lazy[pos];
        //mark the node's children for propagation
        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //no overlap... leave the node
    if(qlow>high||qhigh<low)
        return std::numeric_limits<int>::max();
    //total overlap..return the node
    if(qlow<=low&&qhigh>=high)
        return seg[pos];
    // PARTIAL overlap
        int mid=(low+high)/2;
        return min(query(seg,lazy,low,mid,qlow,qhigh,2*pos+1),query(seg,lazy,mid+1,high,qlow,qhigh,2*pos+2));
}
int main(void) {
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	int size=pow(2,1+ceil(log2(n)))-1;
	int seg[size],lazy[size]={0};
	build(a,seg,0,n-1,0);
	while(q--){
	    int a,l,r;
	    cin>>a>>l>>r;
	    if(a==1){
	        int v;cin>>v;
	        update(seg,lazy,v,0,n-1,l,r,0);
	        cout<<"Tree\n";
	        for(int i=0;i<=15;i++)
	            cout<<seg[i]<<" ";
	        cout<<"\n";
	    }
	    else cout<<query(seg,lazy,0,n-1,l,r,0)<<"\n";
	}
	return 0;
}

