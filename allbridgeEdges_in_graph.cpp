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
vector<pair<int, int>> ans;
void dfsForBridge(int &at, int i, int p, vi &ToA, vi &ENCbV, vb &visited, vvi &adj)
{
    ToA[i] = at;
    ENCbV[i] = at;
    visited[i] = 1;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {

            dfsForBridge(++at, x, i, ToA, ENCbV, visited, adj);
            // now check for bridge edge(i,x):-
            if (ENCbV[x] > ToA[i])
            {
                ans.push_back({i, x});
            }
            ENCbV[i] = min(ENCbV[i], ENCbV[x]);
        }
    }

    for (auto x : adj[i])
    {
        if (x != p)
        {
            ENCbV[i] = min(ENCbV[i], ENCbV[x]);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vvi connections;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }
    // trav(connections)
    // {
    //     deb2(x[0], x[1]);
    //     nline;
    // }
    vvi adj(n);
    trav(connections)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    // linebreak1;
    // for (int i = 0; i < n; i++)
    // {
    //     print(i), print("- ");
    //     trav(adj[i]) print(x);
    //     nline;
    // }

    vi ToA(n);   // ToA[i] stands for Time of Arrival of time of insertion for the node i.
    vi ENCbV(n); // ENCbV[i] stands for "earliest node can be visited by the node i."
    int at = 0;
    vb visited(n, 0);
    dfsForBridge(at, 0, -1, ToA, ENCbV, visited, adj);
    linebreak1;
    debline(ans.size());
    trav(ans)
    {
        deb2(x.first, x.second);
    }
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