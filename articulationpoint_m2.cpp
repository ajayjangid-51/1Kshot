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
void fn(int i, int p, vvi &adj, vi &toa, vi &low, vb &visited, int &at, vi &ans)
{
    toa[i] = at;
    low[i] = at;
    visited[i] = 1;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            fn(x, i, adj, toa, low, visited, ++at, ans);

            low[i] = min(low[i], low[x]);
        }
        else
        {
            // if (p != -1)
            // low[x] = min(low[i], low[x]);
        }
    }
    // now here node i is fully visited,so now we will check that this node i is articulationpoint or not.
    bool ap = 1;
    if (p != -1)
    {

        for (auto x : adj[i])
        {
            if (x != i and x != p and p != -1)
            {

                if (low[x] < toa[i]) // then i is ap.
                {
                    ap = ap and 1;
                }
                else
                {
                    if (x != i)
                        ap = 0;
                }
            }
        }
    }

    if (p == -1)
    {
        int t = 1;
        if (adj[i].size() > 1)
        {
            t = 1;

            for (auto x : adj[i])
            {
                if (low[x] != 0)
                    t = 0;
            }
        }
        if (t == 0)
            // if (adj[i].size() > 1)
            ans.push_back(i);
        // else if (ap == 0)
        //     ans.push_back(i);
    }
    else if (ap == 0)
    {

        // else
        // {

        ans.push_back(i);
        // }
    }
    for (auto x : adj[i])
    {
        if (x != p)
        {
            low[i] = min(low[i], toa[x]);
        }
    }
}
void solve()
{
    int n, e; // "n" means no.ofnodes and "e" stands for no.ofedges and here nodes are indexed zero-based.
    cin >> n >> e;

    vvi adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    print("-:👉🏻graph Adjlist👈🏻:-");
    linebreak1;
    for (int i = 0; i < n; i++)
    {
        print(i), print("-");
        trav(adj[i]) print(x);
        nline;
    }
    linebreak1;

    vi toa(n);
    vi low(n);
    vb visited(n, 0);
    int at = 0;
    vi ans;
    fn(0, -1, adj, toa, low, visited, at, ans);
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