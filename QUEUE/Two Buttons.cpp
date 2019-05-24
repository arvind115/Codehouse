#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int a[100006]={0};
    queue<pair<int,int> > q;
    q.push({n,0});
    vector<int> steps ;
    while( !q.empty() ){
        pair<int,int> p = q.front();
        q.pop();
        int M = p.first;
        if( M>=1 && M<=10000 && ! a[M] ){///not already visited
            if( M == m ){
                steps.push_back(p.second);
                continue;
            }
            q.push({M-1,p.second+1});
            if( M < m ){
                if( M*2 <= 10000 )
                    q.push({M*2,p.second+1});
            }
            a[M] = 1;
        }
    }
    sort(steps.begin(),steps.end());
    cout << steps[0] << endl;
}