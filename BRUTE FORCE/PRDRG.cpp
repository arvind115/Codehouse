#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	vector<pair<int,int> > v;
	v.push_back(make_pair(0,0));
	double prev=0;
	double ans[27]={0};
	for(int i=0;i<=24;i+=2){
	    prev=ans[i];
	    //first
	    int Nr=1,Dr=pow(2,i+1);
	    while((double)Nr/Dr<=prev)
	        Nr+=2;
	   // cout<<i+1<<"="<<Nr<<" "<<Dr<<"\n";
	    v.push_back(make_pair(Nr,Dr));
	    //second
	    Nr=1;
	    Dr=pow(2,i+2);
	    while((double)Nr/Dr<=prev)
	        Nr+=2;
	    v.push_back(make_pair(Nr,Dr));
	    //cout<<i+1<<"="<<Nr<<" "<<Dr<<"\n";
	    ans[i+2]=(double)Nr/Dr;
	    
	}
	int t;cin>>t;
	while(t--){
        int n;cin>>n;
        cout<<v[n].first<<" "<<v[n].second<<" ";
	}
	return 0;
}