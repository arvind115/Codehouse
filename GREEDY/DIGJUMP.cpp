#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INT_MAX 1000000000
typedef long long int ll;
void print(vector<int> v,string s){
    for(int i=0;i<s.length();i++)
        cout<<s[i]<<" ";cout<<endl;
    for(int i=0;i<v.size();i++){
        if(v[i]==INT_MAX){cout<<"* ";continue;}
        cout<<v[i]<<" ";}cout<<endl;
    cout<<endl;
}
int digit(char c){return c-'0';}
int main(){
    string s;cin>>s;int n=s.length();
    if(s.length()==1){cout<<0<<"\n";return 0;}
    vector<int> dig[11];
    for(int i=0;i<n;i++)
        dig[digit(s[i])].pb(i); ///storing the indices of corresponding digit

    vector<int> level(n+1,INT_MAX);
    level[0]=0; ///first digit at level 0
    for(int i=1;i<dig[digit(s[0])].size();i++)
        level[dig[digit(s[0])][i]]=1; ///all duplicates of first digit are at level 1

    while(true){
        bool nochange=true;
        for(int i=1;i<n-1;i++){
            int l=min(level[i-1],level[i+1])+1;
            if(l<level[i]){
                nochange=false;
                level[i]=l;
                ///update all its duplicates
                for(int j=0;j<dig[s[i]-48].size();j++)
                    level[dig[s[i]-48][j]]=min(level[dig[s[i]-48][j]],l+1);
            }
        }
        ///print(level,s);
        if(level[n-2]+1<level[n-1]){
            nochange=false;
            level[n-1]=level[n-2]+1;
        }
        if(nochange)break;
        nochange=true;
        for(int i=n-2;i>=1;i--){
            int l=min(level[i+1],level[i-1])+1;
            if(l<level[i]){
                nochange=false;
                level[i]=l;
                ///update all its duplicates
                for(int j=0;j<dig[s[i]-48].size();j++)
                    level[dig[s[i]-48][j]]=min(level[dig[s[i]-48][j]],l+1);
            }
        }
        if(nochange)break;
        ///print(level,s);
    }
   /// print(level,s);
    cout<<level[s.length()-1]<<endl;
    return 0;
}
/*
72266886688661137700886699445511449955 6
*/
/*94563214791026657896112  4
03333277742111445
023342111445
11234455232442
2222222222222222
222222222222222222222222222222333333333333333333333333333333322222222222222222223333333333333333333333332
012134444444443
023342111445
*/
