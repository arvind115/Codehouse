#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    multiset<ll> Min,Max;
    Min.insert(INT_MAX);Min.insert(INT_MAX);
    int N,q=0;cin>>N;
    while(N--){
        int t;
        cin>>t;
        if(t==1){
            int x; q+=1;
            cin>>x;
            ///firstly insert into 'max' heap of smaller values
            Max.insert(x);
            ///now compare the two heaps & exchange if needed.
            auto mini = Min.begin(),maxi = Max.end(); --maxi;
            if(*maxi > *mini){ ///swap needed
                int large = *maxi, small = *mini;
                Min.erase(Min.begin());
                Min.insert(large);
                Max.erase(maxi);
                Max.insert(small);
            }
            if(q%3==0){ ///insert the largest from Max heap to the Min heap
                auto it = Max.end(); --it;
                int large = *it;
                Min.insert(large);
                Max.erase(it);
            }
        }
        else{
            if(Min.size()<3){
                cout<<"No reviews yet\n";
                continue;}
            auto it = Min.begin(); ///print the min value of max heap
            cout<<*it<<"\n";
        }
    }
    return 0;
}
