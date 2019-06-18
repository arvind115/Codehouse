#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;cin>>tests;
    while(tests--){
        string m,n;
        cin>>m>>n;
        ll nl=n.length();
        ll ml=m.length();
        char N[nl+2][2];
        char M[2][ml+2];
        N[0][0]='a';
        M[0][0]='a';
        if(m[0]=='0'||n[0]=='0'){
            N[1][0]='1';
            M[0][1]='1';
        }
        else{ N[1][0]='0';M[0][1]='0';}
        for(int i=2;i<=n.length();i++){
            if(N[i-1][0]=='0'||n[i-1]=='0')
                N[i][0]='1';
            else N[i][0]='0';
        }
        for(int i=2;i<=m.length();i++){
            if(M[0][i-1]=='0'||m[i-1]=='0')
                M[0][i]='1';
            else M[0][i]='0';
        }
        N[1][1]=M[0][2];
        if(N[2][0]=='0'||M[0][2]=='0'){
            N[2][1]='1';M[1][2]='1';}
        else{ N[2][1]='0';M[1][2]='0';}
        for(int i=3;i<=n.length();i++){
            if(N[i-1][1]=='0'||N[i][0]=='0')
                N[i][1]='1';
            else N[i][1]='0';
        }
        for(int i=3;i<=m.length();i++){
            if(M[1][i-1]=='0'||M[0][i]=='0')
                M[1][i]='1';
            else M[1][i]='0';
        }
        ll queries;
        cin>>queries;
        string ans="";
        while(queries--){
            ll r,c;
            cin>>r>>c;
            if(r>=c){
                if(c==1){
                    ans+=N[r][0];}
                else {//  cout<<N[r-c+2][1]<<endl;
                        ans+=N[r-c+2][1];}
            }
            else if(c>r){
                if(r==1)
                    ans+=M[0][c];
                else
                ans+=M[1][c-r+2];
                }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
