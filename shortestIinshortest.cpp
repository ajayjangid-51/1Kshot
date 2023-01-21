#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
int ans = INT_MAX;
int summ = INT_MAX;
void dfs(int node, vvi &adj, vb &visited, int mini, int &D, map<pii, int> &m, int sum)
{
    visited[node] = 1;
    if (node == D)
    {
        debline(sum);
        if (summ > sum)
        {
            summ = sum;
            ans = mini;
        }
        // ans = mini;
        // return;
    }
    for (auto x : adj[node])
    {
        if (!visited[x])
        {
            dfs(x, adj, visited, min(mini, m[{node, x}]), D, m, sum + m[{node, x}]);
        }
    }
    visited[node] = 0;
}
void solve()
{
    // int A = 7;
    // vvi B = {{1, 2, 2}, {2, 3, 8}, {1, 7, 3}, {7, 4, 2}, {4, 3, 5}, {1, 5, 3}, {5, 3, 7}, {1, 6, 1}};
    // int C = 1, D = 3;
    int A = 4;
    vvi B = {{2, 3, 1}, {3, 1, 9}, {2, 4, 3}, {4, 1, 6}};
    int C = 2, D = 1;
    map<pii, int> m;
    trav(B)
    {
        m[{x[0], x[1]}] = x[2];
        m[{x[1], x[0]}] = x[2];
    }
    trav(m)
    {
        print(x.first.first), print(x.first.second), print("-");
        print(x.second);
        nline;
    }
    vvi adj(A + 1);
    trav(B)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vb visited(A + 1, 0);
    dfs(C, adj, visited, INT_MAX, D, m, 0);
    debline(ans);
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