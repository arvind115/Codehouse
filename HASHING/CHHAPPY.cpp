#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        int x;
        bool happy=false;
        multimap<int,int> m;
        for(int i=0;i<n;i++){
            cin>>x;
            m.insert(make_pair(x,i+1));
        }
        multimap<int,int>::iterator i,j;
        for(i=m.begin();i!=m.end();++i){
            if(m.find((*i).second)!=m.end()){
                j=i;
                ++j;
                while(j!=m.end()&&(*j).first==(*i).first){
                    if(m.find((*j).second)!=m.end()){
                        happy=true;
                        break;
                    }
                    ++j;
                }
                if(happy)break;
            }
            if(happy)break;
        }
        if(happy)cout<<"Truly Happy\n";
        else cout<<"Poor Chef\n";
    }
    return 0;
}
/*
4
4
1 1 2 3
4
2 1 3 3
5
5 4 4 3 1
5
3 2 1 1 4
*/
D
