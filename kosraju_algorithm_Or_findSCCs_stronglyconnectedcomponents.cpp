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
#define size(x) x.size()
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

vvi createReverseGraph(vvi &edgelist, int mxnodeval)
{
    vvi adj(mxnodeval + 1);
    for (auto x : edgelist)
    {
        // adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    return adj;
}
vvi createGraph(vvi &edgelist, int mxnodeval)
{
    vvi adj(mxnodeval + 1);
    for (auto x : edgelist)
    {
        adj[x[0]].push_back(x[1]);
        // adj[x[1]].push_back(x[0]);
    }
    return adj;
}

void dfs1(int node, vvi &adj, vb &visited, vi &v)
{
    visited[node] = 1;
    for (auto x : adj[node])
    {
        if (!visited[x])
            dfs1(x, adj, visited, v);
    }
    v.push_back(node);
}

void dfs2(int node, vvi &adjrev, vb &visited2, vi &c)
{
    visited2[node] = 1;
    for (auto x : adjrev[node])
    {

        if (!visited2[x])
        {
            c.push_back(node);

            dfs2(x, adjrev, visited2, c);
        }
    }
}
void solve()
{
    // kosarajus's algorithm
    // perform 2dfs: dfs1 will create a list of nodes traversed in dfs manner
    // and dfs2 will construct componnets of graph but before dfs2 and after dfs1 we should first reverse the all edges in the graph.

    // create graph: as "adj":-
    // given edgelist:-
    /*   vvi edgelist = {
          {1, 2},
          {1, 4},
          {2, 1},
          {2, 5},
          {3, 2},
          {3, 7},
          {5, 4},
          {6, 3},
          {6, 5},
          {7, 6}}; */

    vvi edgelist = {
        {3, 1},
        {1, 4},
        {3, 4},
        {1, 2},
        {4, 3},
        {0, 2},
        {0, 4}};

    // call creategraph(edgelist)
    int nodes = 5;
    vvi adj = createGraph(edgelist, nodes);
    linebreak1;
    for (int i = 0; i < size(adj); i++)
    {
        print(i), print("-");
        trav(adj[i]) print(x);
        nline;
    }
    linebreak1;

    // dfs1:-
    vi v;
    vb visited(nodes + 1);
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs1(i, adj, visited, v);
        }
    }
    trav(v) print(x);
    linebreak1;

    // now reverse edges:-
    vvi adjrev = createReverseGraph(edgelist, nodes);
    linebreak1;
    for (int i = 0; i < size(adjrev); i++)
    {
        print(i), print("-");
        trav(adjrev[i]) print(x);
        nline;
    }
    linebreak1;

    // dfs2:-
    vb visited2(nodes + 1, 0);
    vvi ans;
    vi c;
    for (int i = nodes - 1; i >= 0; i--)
    {
        if (!visited2[v[i]])
        {
            ans.push_back(c);
            c.clear();
            // c.push_back()
            dfs2(v[i], adjrev, visited2, c);
        }
    }
    ans.push_back(c);

    linebreak1;
    trav(ans)
    {
        trav2(x) print(y);
        nline;
    }
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