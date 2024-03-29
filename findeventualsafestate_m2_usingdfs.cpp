#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pint unsigned int
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int, int>
#define endl "\n"
#define nline cout << "\n"
#define print(x) cout << x << " "
#define siz(x) x.size()
#define trav(a) for (auto x : a)
#define trav2(a) for (auto y : a)
#define range(arr) arr.begin(), arr.end()
#define leftpoint "👈"
#define rightpoint "👉"
#define downpoint "👇"
#define uppoint "👆"
#define fire "🔥"
#define star "⭐"
#define smile "😃"
#define smile2 "👺"
#define debline(x) cout << "👉Line-" << __LINE__ << ": " << #x << " = " << x << endl
#define linebreak2(x) cout << "🟢" << #x << " = " << x << "________________🟢 " << endl
#define all(x) x.begin() x.end()
#define deb(x) cout << #x << "= " << x << "\n"
#define deb2(a, b) cout << #a << "= " << a << " | " << #b << "= " << b << "\n"
#define deb3(a, b, c) cout << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "=" << c << "\n"
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "\n"                              \
                        << "_______________________________" \
                        << "\n"                              \
                           "\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool fn(int i, vb &visited, vi &dp, vvi &adj)
{
    bool b = 1;
    visited[i] = 1;
    for (auto x : adj[i])
    {
        if (visited[x])
        {
            b = 0;
        }
        else if (dp[x] != -1)
        {
            b = b and dp[x];
        }
        else
            b = b and fn(x, visited, dp, adj);
    }
    dp[i] = b;
    visited[i] = 0;
    return dp[i];
}
void solve()
{
    // vvi adj = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vvi adj = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    int n = 5;
    vi dp(n, -1);
    vb visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == -1)
        {
            fn(i, visited, dp, adj);
        }
    }
    vi ans;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != 0)
            ans.push_back(i);
    }
    linebreak1;
    trav(ans) print(x);
    linebreak1;
}

int main()
{
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}