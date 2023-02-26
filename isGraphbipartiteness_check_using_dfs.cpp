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

bool dfs(int node, vvi &adj, vb &visited, vi &color)
{
    visited[node] = 1;
    bool b = 1;
    for (auto x : adj[node])
    {
        if (visited[x])
        {
            if (color[node] == color[x])
            {
                return 0;
            }
        }
        // if (!visited[x] )
        else
        {
            color[x] = !color[node];
            b = b and dfs(x, adj, visited, color);
        }
    }
    return b;
}
void solve()
{
    // 0based inndexing nodenaming is used.
    // vvi adj = {
    //     {1, 2, 3},
    //     {0, 2},
    //     {0, 1, 3},
    //     {0, 2}};
    vvi adj = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};
    int n = 4;
    vb visited(n, 0);
    vi color(n, -1); // -1 means nocolor , 0 meas redcolor , 1 mean blackred.
    color[0] = 0;    // 0th node is of redcolor.
    debline(dfs(0, adj, visited, color));
}

int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}