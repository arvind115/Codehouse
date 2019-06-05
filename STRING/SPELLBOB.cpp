#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        bool bob_found=true;
        string s1,s2;
        cin>>s1>>s2;
        int B=0,O=0;
        for(int i=0;i<3;i++){
            if(s1[i]=='b'||s2[i]=='b')
                B+=1;
        }
        if(B<=1) /// less than 2 'b' present.
            cout<<"no\n";
        else{
            ///cout<<"B="<<B<<"\n";
            for(int i=0;i<3&&bob_found;i++){
                if(s1[i]=='o'){
                    if(s2[i]!='b'||(s2[i]=='b'&&B==3)){
                        cout<<"yes\n";
                        bob_found=false;
                    }
                }
            }
            for(int i=0;i<3&&bob_found;i++){
                if(s2[i]=='o'){
                    if(s1[i]!='b'||(s1[i]=='b'&&B==3)){
                        cout<<"yes\n";
                        bob_found=false;
                    }
                }
            }
            if(bob_found)cout<<"no\n";
        }
    }
    return 0;
}
