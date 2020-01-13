/*
Special Nodes.

This problem was asked in a hiring Challenge on Hackerearth.com.

Problem statement : You are given an undirected tree that contains N nodes.
The tree is rooted at the node 1. Each node has a value assigned to it.
The value of the 'i'th node is denoted by val[i]. For each node, you have to find a special number.

Note:
	* The special number of a node 'u' is the number of factors of bitwise xor of the values of special nodes that are
	not in the subtree of the 'u'.
	* An 'i'th node is called a special node if val[i] is a prime no.
	* A subtree of a node 'u' is the set of nodes which are the descendants of the node 'u'. (including itself).
	* The number of factors of a number must include 1 and the number itself.
	* Assume that the number of factors of 0 is 0.

INPUT FORMAT:
 * First line contains a single integer N
 * Second line: N space-separated integers denoting the value of each node where 'i'th value denotes val[i]
 *Third line: N-1 space-separated integers where 'i'th value denoting the parent of (i+1)th node.

OUTPUT FORMAT:
	Print a single line containing the space-separated special-numbers of each node starting from 1 to n.

CONSTRAINTS:
	* 1 <= N <= 100000
	* 1 <= val[i] <= 1000000
*/
#include <bits/stdc++.h>
using namespace std;
long long int XOR = 0, ans = 0;
vector<int> adj[100004];
int val[100003],subXOR[100004]={0};
bool vis[100004];
int nof(int n){
	int c = 0;
	for(int i=1; i<=sqrt(n);i++){
		if( n%i == 0){
			if( n/i == i)
				c += 1;
			else c += 2;
		}
	}
	///cout<<"factors of "<<n<<" = "<<c<<endl;
	return c;
}
bool prime(int n){
	if( n <= 1)return false;
	if( n <= 3 )return true;
	if( n%2 == 0 || n%3 == 0 )return false;
	for(int i = 5; i*i <=n; i+=6){
		if(n%i == 0 || n%(i+2) == 0)
			return false;
	}
	return true;
}
int dfs(int s){
	if(!vis[s]){
		int subx = 0;
		vis[s] = true;
		if( prime(val[s]) ) /// s is a prime-no
			subx^=val[s]; ///add XOR to the dfs-tree
		for(int i=0; i < adj[s].size(); i++){
			int child = adj[s][i];
			if( !vis[child])
				subx^=dfs(child);
		}
		subXOR[s] = XOR^subx;
		return subx;
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for(int i=1; i <= n; i++){
		cin >> val[i];
		if( prime(val[i]))
			XOR^=val[i];
	}
	for(int i=2; i<=n; i++){
		int par; cin >> par;
		adj[par].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n; i++)
		cout<<nof(subXOR[i])<<" ";cout<<endl;
	return 0;
}
/*
5
7 6 4 1 3
1 1 3 3
*/
