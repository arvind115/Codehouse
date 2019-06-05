///https://www.codechef.com/MAY18B/problems/RD19
#include<bits/stdc++.h>
using namespace std;
int isprime(int n){
    int c=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
            c+=1;
    }
    if(c==1)return 1;
    return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--){
      int N;
      cin>>N;
      int a[N];
      bool one=false;
      for(int i=0;i<N;i++){
        cin>>a[i];
        if(a[i]==1)one=true;
      }
      if(one)
            cout<<"0\n";
      else if(N==1&&a[0]!=1)
        cout<<"-1\n";
      else{ // N>=2 && a[N] doesn't contain '1'
        set<int> s;
        for(int i=0;i<N;i++)
            s.insert(a[i]);
        set<int>::iterator it;
        vector<int> primes;
        for(it=s.begin();it!=s.end();++it){
            if(isprime(*it))
                primes.push_back(*it);
            if(primes.size()>=2){
               // cout<<"more than 2 primes present\n";
                cout<<"0\n";
                break;
            }
        }
       if(primes.size()==0) // no prime present at all. GCD>=2
            cout<<"-1\n";
        else if(primes.size()==1){ // only one prime present. GCD=1 if multiple not present
            bool nonmultiple=false;
            for(int i=0;i<N;i++){
                if(a[i]!=primes[0]&&a[i]%primes[0]!=0){
                    nonmultiple=true;
                    cout<<"0\n";
                    break;
                }
            }
            if(!nonmultiple)
                cout<<"-1\n";
        }
      }
    }
    return 0;
}
