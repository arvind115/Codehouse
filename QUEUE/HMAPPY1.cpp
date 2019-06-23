#include <bits/stdc++.h>
using namespace std;
void ins(multimap<int,int> &m,int a){m.insert(make_pair(a,1));}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,Q,K;
	cin>>N>>Q>>K;
	int s[N+1];
    for(int i=0;i<N;i++)
        cin>>s[i];
    string q;
    cin>>q;
    vector<int>v;
	for(int i=0;i<N;i++){
	    if(s[i]==0){
            v.push_back(0);
            int j =i+1;
            while(j<N&&s[j]==0){
	          j+=1;
	          v.push_back(0);
	        }
	        i=j-1;
	    }
	    else{
	        int t=1,j=i+1;
	        while(j<N&&s[j]==1){
	           t+=1;
	           j+=1;
	        }
	        v.push_back(t);
	        i=j-1;
	   }
	}
	int ans[N+2];
	multimap<int,int> m;
	for(int i=0;i<v.size();i++)
	    ins(m,v[i]);
	multimap<int,int>::iterator it=m.end();
	--it;
	ans[0]=min(K,(*it).first);
	int prev=ans[0];
	if(v.size()==1){
	    for(int x=0;x<q.length();x++){
	        if(q[x]=='?')
	            cout<<prev<<"\n";
	    }
	    return 0;
	}
	for(int i=1;i<N;i++){
	    if(v[0]>=1&&v[v.size()-1]>=1){  //add & subtract
	        it=m.find(v[v.size()-1]);   //find the last element
	        m.erase(it);               //remove it from tree
	        ins(m,v[v.size()-1]-1);  //insert one less of it.
	        it=m.find(v[0]);         //find the first element.
	        m.erase(it);            //remove it from tree.
	        ins(m,v[0]+1);        //add one more of it.
	        //update the vector
	        v[0]+=1;
	        v[v.size()-1]-=1;
	        if(v[v.size()-1]==0)v.pop_back(); //if last element was 1, it would increse 0s.
	        //add the answer
	        it=m.end();--it;
	        ans[i]=min(K,(*it).first);
	        prev=ans[i];
	        continue;
	    }
	    else if(v[0]==0&&v[v.size()-1]==0){ ///Pop & Push zeroes
            v.pop_back();
            v.insert(v.begin(),0);
            ans[i]=prev;
	    }
	    else if(v[0]==0&&v[v.size()-1]>=1){ //insert '1' at front, reduce last element
	       ins(m,1);           // insert 1 in tree.
	       it=m.find(v[v.size()-1]); //find the last element
	       m.erase(it);          //remove last element from tree
	       ins(m,v[v.size()-1]-1); //insert one less of it.
	       //update the vector
	       v.insert(v.begin(),1);
	       v[v.size()-1]-=1;
	       if(v[v.size()-1]==0)v.pop_back(); //control the no of 0s in case last element was 1.
	       it=m.end();--it;
	       ans[i]=min(K,(*it).first);
	       prev=ans[i];
	    }
	    else if(v[0]>=1&&v[v.size()-1]==0){ //Pop 0 and insert at front.
	        v.insert(v.begin(),0);
	        v.pop_back();
	        ans[i]=prev;
	    }
	}
	int I=0;
	for(int i=0;i<q.length();i++){
	    if(q[i]=='!')
	        I+=1;
	   else cout<<ans[I%N]<<"\n";
	}
	return 0;
}
