#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pint unsigned int
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vvl vector<vector<long long>>
#define vvb vector<vb>
#define pii pair<int, int>
#define pll pair<long long, long long>
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
void takegraphinput(long long &n, long long &e, vector<vvl> &adj)
{
    // "n" means no.ofnodes and "e" stands for no.ofedges and here nodes are indexed zero-based.
    cin >> n >> e;
    adj.resize(n);

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
        trav(adj[i]) print("{"), print(x[0]), print(','), print(x[1]), print('}'), print(",");
        nline;
    }
    linebreak1;
}
void solve()
{
    long long n, e;
    vector<vector<vector<long long>>> adj;
    takegraphinput(n, e, adj);
    // pq<distance , node>
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    long long shortestlen = 201 * 10e9;
    pq.push({0, 0});
    vector<long long> dist(n, shortestlen);
    vector<long long> ways(n, 0);
    long long cnt = 0;
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty())
    {
        pll f = pq.top();
        pq.pop();

        for (auto x : adj[f.second])
        {
            if (dist[x[0]] >= f.first + x[1])
            {
                if (dist[x[0]] == f.first + x[1])
                {
                    ways[x[0]] += ways[f.second];
                    continue;
                }

                dist[x[0]] = f.first + x[1];
                ways[x[0]] += ways[f.second];
                // if (x[0] == n - 1)
                // {
                //     if (dist[x[0]] > shortestlen)
                //         continue;
                //     shortestlen = dist[x[0]];
                //     cnt++;
                // }
                // else
                pq.push({dist[x[0]], x[0]});
            }
        }
    }
    debline(ways[n - 1]);
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