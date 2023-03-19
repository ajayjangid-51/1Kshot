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

void solve()
{
    int n, e;
    cin >> n >> e;
    vvi edges;
    for (int i = 0; i < e; i++)
    {
        vi edge(3);
        cin >> edge[0] >> edge[1] >> edge[2];
        edges.push_back(edge);
    }
    // trav(edges) deb2(x[0], x[1]);
    vector<vector<pair<int, int>>> adj(n);
    for (auto x : edges)
    {
        adj[x[0]].push_back({x[1], x[2]});
        // adj[x[1]].push_back(x[0]);
    }
    linebreak1;
    int i = 0;
    trav(adj)
    {
        print(i++), print("-");
        trav2(x) print(y.first), print(y.second), print(",");
        nline;
    }
    linebreak1;
    //
    vi dist(n, -1);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();

        // if (dist[t.first] != -1)
        //     dist[t.first] = min(dist[t.first], t.second);
        // else
        deb3(smile2, t.first, t.second);
        if (dist[t.first] == -1)
            dist[t.first] = t.second;
        else
            dist[t.first] = min(dist[t.first], t.second);
        for (auto x : adj[t.first])
        {
            if (dist[x.first] == -1)
            {
                q.push({x.first, t.second + x.second});
            }
            else
            {
                // debline(x);
                // debline(dist[x]);
                dist[x.first] = min(dist[x.first], t.second + x.second);
            }
        }
    }
    linebreak1;
    trav(dist) print(x);
    linebreak1;
}
void printSquare(int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        if (i == 0 or i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
            continue;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 or j == n - 1)
                {
                    cout << "*";
                }
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
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