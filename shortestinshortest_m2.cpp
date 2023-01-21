#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "_______________________________" \
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
vector<long long> findShortestPaths(int A, int src, vector<vector<pair<int, int>>> &adj)
{
    vector<long long> d(A, LLONG_MAX);
    vector<bool> vis(A, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    d[src] = 0;
    pq.push({0,
             src});

    while (pq.size())
    {
        int node = pq.top().second;
        long long dis = pq.top().first;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        for (auto pr : adj[node])
        {
            if (d[node] + pr.second < d[pr.first])
            {
                d[pr.first] = d[node] + pr.second;
                pq.push({d[pr.first],
                         pr.first});
            }
        }
    }
    return d;
}
void solve()
{
    int A = 7;
    vvi B = {{1, 2, 2}, {2, 3, 8}, {1, 7, 3}, {7, 4, 2}, {4, 3, 5}, {1, 5, 3}, {5, 3, 7}, {1, 6, 1}};
    int C = 1, D = 3;
    // int A = 4;
    // vvi B = {{2, 3, 1}, {3, 1, 9}, {2, 4, 3}, {4, 1, 6}};
    // int C = 2, D = 1;

    vector<vector<pair<int, int>>> adj(A);
    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0] - 1].push_back({B[i][1] - 1,
                                    B[i][2]});
        adj[B[i][1] - 1].push_back({B[i][0] - 1,
                                    B[i][2]});
    }

    vector<long long> dC = findShortestPaths(A, C - 1, adj);
    linebreak1;
    trav(dC) print(x);
    linebreak1;

    long long shortestPath = dC[D - 1];
    debline(shortestPath);

    vector<long long> dD = findShortestPaths(A, D - 1, adj);
    linebreak1;
    trav(dD) print(x);
    linebreak1;

    int ans = INT_MAX;
    for (int i = 0; i < B.size(); i++)
    {
        if (dC[B[i][0] - 1] + B[i][2] + dD[B[i][1] - 1] == shortestPath)
        {
            ans = min(ans, B[i][2]);
        }
        if (dC[B[i][1] - 1] + B[i][2] + dD[B[i][0] - 1] == shortestPath)
        {
            ans = min(ans, B[i][2]);
        }
    }

    // return ans;
    debline(ans);
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