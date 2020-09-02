// https://codeforces.com/contest/676/problem/C

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n + 2] = {0}, b[n + 2] = {0};
    a[0] = s[0] == 'a';
    b[0] = !a[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + (s[i] == 'a');
        b[i] = b[i - 1] + (s[i] == 'b');
    }
    int ans = 1, l = 0, r = 0;
    while (l <= r && r < n)
    {
        bool A = false, B = false;
        int len = r - l + 1;
        int As = a[r] - a[l] + (s[l] == 'a');
        if (As + k >= len)
            A = true;
        int Bs = b[r] - b[l] + (s[l] == 'b');
        if (Bs + k >= len)
            B = true;
        if (A || B)
        {
            ans = max(ans, len);
            r += 1;
        }
        else
            l += 1;
    }
    cout << ans << endl;
    return 0;
}