///http://codeforces.com/problemset/problem/550/C
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool f(char a,char b ,char c){
    int no =0;
    no=no*10+a-'0';
    no=no*10+b-'0';
    no=no*10+c-'0';
    return no%8 == 0;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    vector<int> v;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){cout<<"YES\n0\n";return 0;}
        if(s[i]=='8'){cout<<"YES\n8\n";return 0;}
        for(int j=i+1;j<n;j++){
            if(s[j]=='0'){cout<<"YES\n0\n";return 0;}
            if(s[j]=='8'){cout<<"YES\n8\n";return 0;}
            if( ((s[i]-'0')*10+s[j]-'0')%8==0 ){cout<<"YES\n"<<s[i]<<s[j];return 0;}
            for(int k=j+1;k<n;k++){
                if(s[k]=='0'){cout<<"YES\n0\n";return 0;}
                if(s[k]=='8'){cout<<"YES\n8\n";return 0;}
                if(f(s[i],s[j],s[k])){
                    cout<<"YES\n";
                    cout<<s[i]<<s[j]<<s[k]<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
/*

*/