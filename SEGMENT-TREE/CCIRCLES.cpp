///https://www.codechef.com/OCT18B/problems/CCIRCLES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=1000002;
ll seg[2097152]={0};
ll lazy[2097152]={0};
void update(ll seg[],ll lazy[],ll value,ll low ,ll high,ll qlow,ll qhigh,ll pos){
    if(low>high)return ;
    if(lazy[pos]!=0){ //propagation needs to be done
        seg[pos]+=lazy[pos];
        if(low!=high){//not a leaf node...so propagate 'down'
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>qhigh||high<qlow)  //no overlap...leave the node
        return;
    if(qlow<=low&&high<=qhigh){ //total overlap
        seg[pos]+=value;
        if(low!=high){
            lazy[2*pos+1]+=value;
            lazy[2*pos+2]+=value;
        }
        return ;  //total overlap
    }
    //control arrives here only in case of PARTIAL overlap
    ll mid=(low+high)/2;
    // traverse to the LEFT first
    update(seg,lazy,value,low,mid,qlow,qhigh,2*pos+1);
    // traverse to the RIGHT then
    update(seg,lazy,value,mid+1,high,qlow,qhigh,2*pos+2);
    //updation done... now 'update of MIN' value to be done
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
ll query(ll seg[],ll lazy[],ll low,ll high,ll qlow,ll qhigh,ll pos){
    if(low>high)return 0;
    //no overlap... leave the node
    if(high<qlow||qhigh<low)
        return 0;
    if(lazy[pos]!=0){ //check for pending propagations
        seg[pos]+=lazy[pos];
        //mark the node's children for propagation
        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //total overlap..return the node
    if(qlow<=low&&high<=qhigh)
        return seg[pos];
    // PARTIAL overlap
    else{
        ll mid=(low+high)/2;
        return (query(seg,lazy,low,mid,qlow,qhigh,2*pos+1)+query(seg,lazy,mid+1,high,qlow,qhigh,2*pos+2));
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll N,Q;
    cin>>N>>Q;
    double a[N+1][3];
    for(ll i=0;i<N;i++){  ///input circles
        double x,y,r;
        cin>>x>>y>>r;
        a[i][0]=x;
        a[i][1]=y;
        a[i][2]=r;
    }          /// preprocess all circles.
    for(ll i=0;i<N;i++){
        double r1=a[i][2];
        for(ll j=i+1;j<N;j++){
            double r2=a[j][2];
            double mn,mx;
            double d=sqrt(pow(a[i][0]-a[j][0],2)+pow(a[i][1]-a[j][1],2)); ///distance b/w centres.
            if(d>=r1+r2){ //not intersecting... (maybe at one point)
                mn=d-(r1+r2);
                mx=d+r1+r2;
            }
            else if(max(r1,r2)>=d+min(r1,r2)){  ///one circle inside another
                mn=max(r1,r2)-(d+min(r1,r2));
                mx=r1+r2+d;
            }
            else if(d<r1+r2){ /// intersecting
                mn=0;
                mx=d+r1+r2;
            }
            else if(d==0){ ///coinciding
                mn=mx=max(r1,r2)-min(r1,r2);//cout<<"coinciding\n";
            }

            update(seg,lazy,1,0,n-1,ll(ceil(mn)),ll(floor(mx)),0);
        }
    }
    while(Q--){
        ll K;
        cin>>K;
        cout<<query(seg,lazy,0,n-1,K,K,0)<<"\n";
    }
    return 0;
}
