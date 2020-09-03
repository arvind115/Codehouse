//https://codeforces.com/contest/839/problem/C

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vis[100005] = {false}, vis2[100005] = {false};
int dist[100005] = {0}, children[100005] = {0};
long double prob[100005], ans = 0;

void dfs(int s, int d)
{
    if (!vis[s])
    {
        vis[s] = true;
        for (int i = 0; i < adj[s].size(); i++)
        {
            int child = adj[s][i];
            if (!vis[child])
            {
                children[s] += 1;
                dist[child] = d + 1;
                dfs(child, dist[child]);
            }
        }
    }
}

void dfs2(int s, long double p)
{
    if (!vis2[s])
    {
        vis2[s] = true;
        int chds = children[s];
        if (chds == 0)
        {
            ans += (long double)(p * dist[s]);
            return;
        }
        for (int i = 0; i < adj[s].size(); i++)
        {
            int child = adj[s][i];
            if (!vis2[child])
            {
                long double pr = (long double)(p / children[s]);
                dfs2(child, pr);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    prob[1] = 1;
    dist[1] = 1;
    dfs(1, 0);
    dfs2(1, 1);
    cout.precision(8);
    cout << fixed << ans << endl;
    return 0;
}