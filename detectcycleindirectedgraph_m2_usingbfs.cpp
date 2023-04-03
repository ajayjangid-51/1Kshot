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
    }
}
void solve()
{
    // the idea for bfs is that ki agr koi node apne parent se upr wale level meh ja rha hai then mtlb surely cycle hai.
    // this pure bfs will not work efficiently , mtlb we have to first check for undirected edge in graph and also check for all nodes as starting nodes.
    // allover this bfs wil not work, bcoz levels of nodes are can be from -inifinty to +infinity instead from 0 to +inifiniy.
    // so as per the bfs we can do it by via kahn's bfs algo for toposort, q ki as we know in directedcyclicgraph toposort can't be constructed so mtlb in via kahn's algorithm our toposort array will not be of size of no.ofnodes if the graph has cycle init.
    int n, e;
    vvi adj;
    inputgraph(n, e, adj);
    linebreak1;
    for (int i = 0; i < n; i++)
    {
        print(i), print("-");
        trav(adj[i]) print(x);
        nline;
    }

    vi level(n, -1);
    vi visit(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visit[i])
        {
            deb(i);
            continue;
        }
        queue<int> q; // pair<node>
        q.push(i);
        level[i] = 0;
        while (!q.empty())
        {
            int f = q.front();
            visit[f] = 1;
            q.pop();
            for (auto x : adj[f])
            {
                if (x == f)
                {
                    debline("yes");
                    return;
                }
                if (level[x] != -1 and level[x] < level[f])
                {
                    debline("yes");
                    return;
                }
                if (level[x] == level[f])
                    continue;
                level[x] = level[f] + 1;
                q.push(x);
            }
        }
    }

    debline("no cycle");
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