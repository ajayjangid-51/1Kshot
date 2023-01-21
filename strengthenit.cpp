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
vector<int> comps;
int dfs(int s, vector<vi> &adj, vector<bool> &visited, int &nodes)
{
    // Adding all the edges connected to the vertex
    int adjListSize = adj[s].size();
    visited[s] = true;
    for (long int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            adjListSize += dfs(adj[s][i], adj, visited, nodes);
        }
    }
    return adjListSize;
}

int maxEdges(vvi &adj, int &nodes)
{
    int res = INT_MIN;
    vector<bool> visited(nodes, false);
    for (long int i = 1; i <= nodes; i++)
    {
        if (visited[i] == false)
        {
            int adjListSize = dfs(i, adj, visited, nodes);
            deb(adjListSize / 2);
            comps.push_back(adjListSize / 2);
            res = max(res, adjListSize / 2);
        }
    }
    return res;
}
void solve()
{
    // int A = 7;
    int A = 2;
    // vvi B = {{1, 2}, {2, 3}, {3, 1}, {4, 5}, {5, 6}, {6, 4}};
    vvi B = {{2, 2}};
    // int C = 2;
    int C = 6;
    vvi adj(A + 1);
    trav(B)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    linebreak1;
    trav(adj)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
    int ans = maxEdges(adj, A);
    // deb("hi");
    debline(ans);
    int t = 0;
    sort(comps.rbegin(), comps.rend());
    for (int i = 0; i < C + 1 and i < comps.size(); i++)
    {
        t += comps[i];
    }
    debline(t + C);
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