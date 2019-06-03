///https://www.codechef.com/problems/XORSUB
#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=8&(1<<(3-1)); /// no&(1<<(k-1)) is non-0 if 'kth' bit is set
    int t;cin>>t;
    while(t--){
        int N,K;cin>>N>>K;
        int xors[1100]={0};
        for(int i=0;i<N;i++){
            int a;cin>>a;
            xors[a]=1;
            for(int i=1;i<=1050;i++){
                if(xors[i])
                    xors[a^i]=1;
            }
        }
        int ans=K;
        for(int i=1;i<=1050;i++){
            if(xors[i])
                ans=max(ans,ans^i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
3 4
4 4 4
*/
