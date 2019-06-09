#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int P,S;
    cin>>P>>S;
    vector< pair<int,int> >v[P];
    vector<pair<int,int> > d; ///difficulty vector
    for(int i=0;i<P;i++){
        int a[S],b[S];
        for(int j=0;j<S;j++)
            cin>>a[j];
        for(int j=0;j<S;j++)
            cin>>b[j];
        for(int j=0;j<S;j++)
            v[i].push_back((make_pair(a[j],b[j])));
        sort(v[i].begin(),v[i].end());
        d.push_back(make_pair(0,i+1));
    }
    vector<pair<int,int> >::iterator it;
    for(int i=0;i<P;i++){
        for(it=v[i].begin()+1;it!=v[i].end();++it){
            if(it->second<(it-1)->second)
                d[i].first+=1;
        }
    }
    sort(d.begin(),d.end());
    for(it=d.begin();it!=d.end();++it)
        cout<<it->second<<"\n";
    return 0;
}
