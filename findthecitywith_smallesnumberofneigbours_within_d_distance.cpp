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
    int nodes, e, d;
    cin >> nodes >> e >> d;
    vvi edgelist;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edgelist.push_back({a, b, w});
    }
    vvi v(nodes + 1, vi(nodes + 1, 1e8));
    int n = nodes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                v[i][j] = 0;
        }
    }
    for (auto x : edgelist)
    {
        v[x[0]][x[0]] = 0;
        v[x[1]][x[1]] = 0;
        v[x[0]][x[1]] = x[2];
        v[x[1]][x[0]] = x[2];
    }

    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
    for (int k = 0; k < nodes; k++)
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                v[i][j] = min(v[i][j], (v[i][k] + v[k][j]));
            }
        }
    }

    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;

    int mini = nodes + 1;
    int ans = -1;
    for (int i = 0; i < nodes; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nodes; j++)
        {
            if (v[i][j] <= d)
                cnt++;
        }
        // deb(cnt);
        deb2(i, cnt);
        if (cnt <= mini)
        {
            mini = cnt;
            ans = i;
        }
    }
    debline(ans);
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