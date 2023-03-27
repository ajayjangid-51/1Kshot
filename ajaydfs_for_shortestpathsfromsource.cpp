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
void dfs(int i, vi &dist, vector<vector<pii>> &adj)
{
    for (auto x : adj[i])
    {
        if (dist[x.first] > dist[i] + x.second)
        {
            dist[x.first] = dist[i] + x.second;
            dfs(x.first, dist, adj);
        }
    }
    // okay the reason gotit why this ajaydfsforshortestpath is giving tle as  q ki dfs meh ek node multiple times visits hoskta hai as q ki voh nodes multiple times decreament hosktehh hai. jaise see this photoexample.
    // https://drive.google.com/file/d/15OW-umXpRb6eFbetzhtmqEPyKNjnXA5a/view?usp=share_link
}
void solve()
{
    int n, e; // "n" means no.ofnodes and "e" stands for no.ofedges and here nodes are indexed zero-based.
    cin >> n >> e;

    vector<vector<pii>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    print("-:👉🏻graph Adjlist👈🏻:-");
    linebreak1;
    for (int i = 0; i < n; i++)
    {
        print(i), print("-");
        trav(adj[i]) print("{"), print(x.first), print(','), print(x.second), print('}'), print(",");
        nline;
    }
    linebreak1;
    vi dist(n, 1e8);
    int s = 1;
    dist[s] = 0;

    dfs(s, dist, adj);

    linebreak1;
    trav(dist) print(x);
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