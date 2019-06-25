///https://www.codechef.com/FEB19A/problems/ARTBALAN
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int fn(multiset<int> s ,int G,int V){///returns min no of steps to convert elements of s into a group of size G with value V
    int ans=0;
    multiset<int>::iterator it;
    while(!s.empty()){
        it=s.end();--it;
        int last=*(it); ///end value
        if(last==V){ ///already equal to V, discard it.
            s.erase(s.find(last));
            continue;
        }
        if(last>V){ ///it can donate some amount to next largest value
            ///find the next largest to 'accept' excess amount from 'last'
            ///if no one can accept, add excess amount to the set....actually add min(excess,V)
            int tofind=V-1;bool notfound=true; ///only < V values can accept some amount.
            while(tofind>0){
                if(s.find(tofind)!=s.end()){
                    notfound=false;
                    s.erase(s.find(tofind)); ///erase the old value from set. updated will be added later.
                    break;
                }
                else tofind-=1;
            }
            if(!notfound){ ///some amount can be donated. (to 'tofind')
                int req = V-tofind;
                int todonate = last-V;
                if(req > todonate){ ///all excess amt can be donated. discard 'last' from set,add updated 'tofind' to set.
                    s.erase(s.find(last)); ///last becomes = V
                    s.insert(tofind+todonate); ///add updated tofind to set.
                    ans+=todonate;
                }
                else if(req<todonate){ ///only some amt can be donated.'last' doesn't become = V, while 'tofind' beocmes = V
                    ///only add reduced 'last' back to the set.update ans.
                    s.erase(s.find(last));
                    s.insert(last-req);
                    ans+=req;  ///tofind becomes = V
                }
                else if(req==todonate){ ///both 'last' & 'tofind' become = V ...discard both
                    ans+=req;
                    s.erase(s.find(last));
                }
            }
            else if(notfound){ ///no-one could accept, add min(excess,V) to the set.
                s.erase(s.find(last));
                s.insert(last-V);s.insert(V);
                ans+=min(V,last-V);
            }
        }
        else if(last<V){ ///it will accept the smallest value....actually accepts min(smallest,required)
            int req = V-last;
            int avl = *(s.begin());
            if(avl>req){ ///more than required. last becomes = V  discard it  ...add reduced 'avl' to set.update ans+=req
                 s.erase(s.find(last));
                 s.erase(s.begin());
                 s.insert(avl-req);
                ans+=req;
            }
            else if(avl<req){ ///avl = 0, discard from set.add updated last to set. update ans+=avl
                s.erase(s.begin());
                s.erase(s.find(last)); ///erase lower last value.
                s.insert(last+avl); ///insert increased last value.
                ans+=avl;
            }
            else if(avl==req){ ///avl becomes = 0 and last becomes = V
                s.erase(s.find(last));
                s.erase(s.begin());
                ans+=avl;
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        string S;cin>>S;
        int N=S.length();
        int f[27]={0};
        for(int i=0;i<N;i++)
            f[S[i]-'A']+=1;
        multiset<int> s;
        for(int i=0;i<26;i++){
            if(f[i]>0)
                s.insert(f[i]);
        }
        vector<int> m;
        for(int i=1;i<=N;i++){ ///handle separately for i=1
            if(N%i==0&&i<=26)
                m.push_back(i);
        }
        int ans=999888777;
        for(int i=0;i<m.size();i++){
            int temp = fn(s,m[i],N/m[i]);
            ans=min(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
AAABBBCCCDDDDDDDDD
*/
