///http://codeforces.com/problemset/problem/476/B
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int fact(int n){
    if(n==0)return 1;
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,s2;
    cin>>s;
    cin>>s2;
    int source=0,dest=0,noq=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+')
            source+=1;
        else source-=1;
        if(s2[i]=='+')
            dest+=1;
        else if(s2[i]=='-')
            dest-=1;
        else noq+=1;
    }
    if( dest==source && noq==0 ){cout<<"1.000000000000\n";return 0;}
    int req = abs(source-dest);
    if( req > noq ){cout<<"0.000000000000\n";return 0;} ///not possible
    else if( req%2 == 0 && noq%2 != 0 ){ ///even no can't be formed with odd no of elements
        cout<<"0.000000000000\n"; return 0;
    }
    else if( req%2 !=0 && noq%2 == 0 ){ ///odd no can't be formed with even no of elements.
        cout<<"0.000000000000\n"; return 0;
    }
    ///req <= noq
    int a=0,b=req;
    while(a+b<noq){
        a+=1;
        b+=1;
    }
    long double ans;
    long double Nr = fact(noq);
    Nr = (ld)(Nr/(fact(a)*(fact(b))));
    long double Dr = pow(2,noq);
    ans = (ld)Nr/Dr;
    ///cout<<"nr="<<Nr<<" Dr = "<<Dr<<endl;
    std::cout<<std::setprecision(12)<<std::fixed;
    cout<<ans;
    return 0;
}
/*
++-+-
+-+-+

*/