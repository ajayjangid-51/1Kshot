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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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
bool dfs(int node, int &n, vvi &adj, vb &vis, vb &pathvis)
{
    if (vis[node] and pathvis[node])
        return 1;
    // if (vis[node])
    //     return 0;
    bool ans = 0;
    for (auto x : adj[node])
    {
        if (vis[node])
            continue;
        vis[node] = 1;
        pathvis[node] = 1;
        ans = ans || dfs(x, n, adj, vis, pathvis);
        pathvis[node] = 0;
    }
    return ans;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    vvi edges;
    vvi adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        adj[a].push_back(b);

        // for undirected:-
        // adj[b].push_back(a);
    }
    for (int i = 0; i < e; i++)
    {
        cout << edges[i][0] << ' ' << edges[i][1] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        print(i), print(" - ");
        trav(adj[i]) print(x);
        nline;
    }

    // detect cycle using dfs. ( where bfs approach is find topsort and if toposort contains all elements then cycle in not else cycle is present. )
    // dfs idea is we take 2arrays (visit and pathvisit) where visit[i] says that node-i is visited and pathvisit-array says that on current instant, the path which we are following or walking through dfs contains these all nodes which are marked as 1(i.e. pathvisit[i] = 1).

    vb vis(n, 0), pathvis(n, 0);
    bool cycle = dfs(0, n, adj, vis, pathvis);
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