///http://codeforces.com/problemset/problem/1117/A
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while ( t-- ){
        int n ; cin >> n;
        string s[n+2];
        for( int i=0; i<n; i++)
            cin >> s[i];
        int ans=0;
        int col[n+3]={0};
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
               // if( col[j] ) ///set column, skip it
                 //   continue;
                if( s[i][j] == '#'){ ///set the column & skip the row
                    col[j] = 1;
                    //cout<<"setting column "<<j+1<<endl;
                    break;
                }
                else if( s[i][j]=='.' && !col[j]){
                    if( i+1<=n-1 && s[i+1][j]=='#'){
                        col[j]=1;
                        //cout<<"setting column "<<j+1<<endl;
                        continue;
                    }
                    if( !col[j]){
                        ans+=1;
                        ///cout<<i+1<<","<<j+1<<endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
5
.#...
....#
...#.
....#



..#..
....#
.....
.##.#
...#.
1
4
#..#
#..#
#..#
#..#
*/
