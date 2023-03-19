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

bool isokay(int node, int k, vi &color, vvi &adj)
{
    for (auto x : adj[node])
    {
        if (color[x] == k)
            return 0;
    }
    return 1;
}

bool fn(int node, int m, vi &color, vvi &adj)
{
    for (auto x : adj[node])
    {
        if (color[x] == -1)
        {
            for (int k = 0; k < m; k++)
            {
                if (isokay(x, k, color, adj))
                {
                    color[x] = k;
                    if (fn(x, m, color, adj))
                    {
                        return 1;
                    }
                    color[x] = -1;
                }
            }
            return false;
        }
    }
    return 1;
}
void solve()
{
    /*  vvi edges = {
         {0, 1},
         {1, 2},
         {2, 3},
         {3, 0},
         {2, 0}}; */
    // vvi edges = {
    //     {0, 1},
    //     {1, 2},
    //     {2, 0}};
    // vvi edges = {
    //     {1, 2},
    //     {2, 3},
    //     {3, 4},
    //     {1, 4},
    //     {1, 3}};
    // vvi edges = {
    //     {1, 5}, {3, 5}, {5, 4}};

    // vvi edges = {
    //     {4, 6}, {2, 5}, {6, 10}, {8, 10}, {3, 10}, {9, 10}, {5, 10}, {7, 8}, {1, 9}, {8, 9}, {1, 5}, {5, 9}, {2, 6}, {5, 7}};
    int e;
    cin >> e;
    vvi edges(e);
    int n;
    cin >> n;

    vvi adj(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        deb2(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        // adj[x[0]].push_back(x[1]);
        // adj[x[1]].push_back(x[0]);
    }

    linebreak1;
    int t = 0;
    trav(adj)
    {
        print(t++), print("-");

        trav2(x) print(y);
        nline;
    }
    linebreak1;
    int m;
    cin >> m;
    vi color(n, -1);
    for (int j = 0; j < n; j++)
    {
        if (color[j] == -1)
        {
            for (int i = 0; i < m; i++)
            {
                color[j] = i;
                if (fn(j, m, color, adj) == false)
                {
                    debline("false");
                    return;
                }

                color[j] = -1;
            }
        }
    }
    debline("true");
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