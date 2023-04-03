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
void inputMatrix(int &n, int &m, vvi &M)
{
    cin >> n >> m;
    M.resize(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
}
int x[4] = {-1, +1, 0, 0};
int y[4] = {0, 0, -1, +1};

void dfs(int i, int j, vvb &visited, vvi &v)
{
    v[i][j] = 0;
    for (int d = 0; d < 4; d++)
    {
        int i1 = i + x[d];
        int j1 = j + y[d];
        if (i1 >= 0 and i1 < v.size() and j1 >= 0 and j1 < v[0].size() and v[i1][j1] == 1)
        {
            dfs(i1, j1, visited, v);
        }
    }
}
void solve()
{
    int n, m;
    vvi v;
    inputMatrix(n, m, v);
    vvb visited(n, vb(m, 0));
    for (int i = 0; i < n; i++)
    {
        /*  for (int j = i; (i == 0) ? j < m : (i == n - 1) ? j >= 0
                                                         : j < 0;
              (i == 0) ? j++ : j--)
         {
             print(v[i][j]);
         } */

        for (int j = 0; j < m; j++)
        {
            if (v[0][j] == 1)
                dfs(0, j, visited, v);
            if (v[n - 1][j] == 1)
            {
                dfs(n - 1, j, visited, v);
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i][m - 1] == 1)
            {
                dfs(i, m - 1, visited, v);
            }
            if (v[i][0] == 1)
            {
                dfs(i, 0, visited, v);
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