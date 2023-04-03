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
void inputgraph(int &n, int &e, vvi &adj)
{
    // 0 based indexing nodes.
    print("input the no. of nodes and no.of edges and then edges");
    cin >> n >> e;
    adj.resize(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
bool fn(int i, int p, vb &vstart, vi &vdone, vvi &adj)
{

    bool cycle = 0;
    vstart[i] = 1;
    for (auto x : adj[i])
    {
        if (x == p)
            continue;
        deb3(x, i, smile2);
        if (vstart[x])
        {

            cycle = 1;
        }
        else if (vdone[x] != -1)
            cycle = cycle or vdone[x];
        else
            cycle = cycle or fn(x, i, vstart, vdone, adj);
    }

    vstart[i] = 0;
    vdone[i] = cycle;
    return cycle;
}
void solve()
{
    int n, e;
    vvi adj;
    inputgraph(n, e, adj);
    linebreak1;
    trav(adj)
    {
        trav2(x) print(y);
        nline;
    }

    vb vstart(n, 0); // vstart(visitstart)
    vi vdone(n, -1); // vdone(visitdone)
    bool cycle = 0;
    for (int i = 0; i < n; i++)
    {
        if (vdone[i] == -1)
        {
            bool b = fn(i, -1, vstart, vdone, adj);
            deb(b);
            cycle = cycle or b;
            // fn(i, vstart, vdone, adj);
            debline(cycle);
        }
    }

    debline(cycle);
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