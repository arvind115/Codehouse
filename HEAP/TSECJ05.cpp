#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        multiset<int> s;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(s.size()<k){ ///if size < K, then insert.
                s.insert(x);
                if(s.size()>=k)
                    cout<<*s.begin()<<" ";
                else cout<<"-1 ";
            }
            else{ ///size >= K, compare then insert
                if(x>*s.begin()){
                    s.insert(x);
                    s.erase(s.begin());
                }
                cout<<*s.begin()<<" ";
            }
        }
        cout<<"\n";
    }
	return 0;
}
/*
2
4 6
1 2 3 4 5 6
1 4
4 3 6 5
*/
