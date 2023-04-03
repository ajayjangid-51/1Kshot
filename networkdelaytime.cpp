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
void takegraphinput(int &n, int &e, vector<vvi> &adj)
{
    // "n" means no.ofnodes and "e" stands for no.ofedges and here nodes are indexed zero-based.
    cin >> n >> e;
    n++;
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        // adj[b].push_back({a, w});
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
    int n, e, k;
    vector<vvi> adj;
    takegraphinput(n, e, adj);
    cin >> k;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int maxi = -1;
    pq.push({0, k});
    vi dist(n, 110000);
    dist[k] = 0;

    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();
        for (auto x : adj[f.second])
        {
            if (dist[x[0]] > f.first + x[1])
            {
                dist[x[0]] = f.first + x[1];
                // maxi = max(maxi, dist[x[0]]);
                pq.push({dist[x[0]], x[0]});
            }
        }
    }

    linebreak1;
    trav(dist) print(x);
    // debline(maxi);
    for (int i = 1; i < n; i++)
    {
        if (dist[i] == 110000)
        {
            debline("-1");
            return;
        }
        maxi = max(maxi, dist[i]);
    }
    debline(maxi);
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