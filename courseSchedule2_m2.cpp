#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define size(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "_______________________________" \
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
void fn(int i, stack<int> &s, vb &visited, vvi &adj)
{
    // deb(i);
    visited[i] = 1;
    for (auto x : adj[i])
    {
        // deb(x);
        if (!visited[x])
        {
            fn(x, s, visited, adj);
        }
    }
    s.push(i);
}
void solve()
{
    // int a = 4;
    int a = 2;
    // vvi adj = {{1, 2}, {3}, {3}, {}};
    vvi adj = {{1}, {0}};
    int n = size(adj);
    stack<int> s;
    vb visited(a, 0);
    for (int i = 0; i < a; i++)
    // for (int i = 0; i < 1; i++)
    {
        if (!visited[i])
        {
            fn(i, s, visited, adj);
        }
    }
    vi ans;
    // print("hi");
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}