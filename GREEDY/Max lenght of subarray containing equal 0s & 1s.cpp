#include <bits/stdc++.h>
using namespace std;
int f(int pre[],int left, int right){
    if(left > right)
        return 0;
    if( left == 0 )++left;
    int length = right - left + 1;
    int zeroes = pre[right] - pre[left-1];
    if( zeroes == length/2)
        return length;
    int ans = max(f(pre,left+1,right),f(pre,left,right-1));
    return ans;
}
int main() {
    int n; cin >> n;
	vector<int> a(n+2);
	for(int i=1; i<=n; i++)
	     cin >> a[i];
	int pre[n+2]; pre[0] = 0 ;
	for(int i=1; i<=n; i++){
	    if( a[i] == 0 ){
	        ///cout<<"at "<<i<<endl;
	        pre[i] = pre[i-1]+1;
	    }
	    else pre[i] = pre[i-1];
	}
	for(int i=1; i<=n;i++)
	    cout << pre[i] << " "; cout << endl;
	int l = f(pre,0,n);
	cout << l <<endl;
	return 0;
}