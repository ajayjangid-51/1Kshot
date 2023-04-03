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
vvi takematrixinput()
{
    int n, m;
    cin >> n >> m;
    vvi mat(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    return mat;
}
void printmatrix(vvi &mat)
{
    int row = mat.size();
    if (row == 0)
    {
        print("empty matrix:");
        return;
    }
    int column = mat[0].size();
    nline;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            print(mat[i][j]);
        }
        nline;
    }
}
// int x[4] = {-1, +1, 0, 0};
// int y[4] = {0, 0, -1, +1};
//           d  r u  l
int x[4] = {+1, 0, -1, 0};
int y[4] = {0, +1, 0, -1};
int dfs(int i, int j, vi &l, vvb &visited, vvi &dp, vvi &v)
{
    // if (i == v.size() - 1 and j == v[0].size() - 1)
    //     return 0;
    // if (dp[i][j] != INT_MAX)
    // {
    //     visited[i][j] = 0;
    //     return dp[i][j];
    // }
    visited[i][j] = 1;
    vi a;
    for (int d = 0; d < 4; d++)
    {
        int i1 = i + x[d];
        int j1 = j + y[d];
        if (i1 >= 0 and i1 < v.size() and j1 >= 0 and j1 < v[0].size() and !visited[i1][j1])
        {

            a.push_back(abs(v[i][j] - v[i1][j1]));
            int t = dfs(i1, j1, l, visited, dp, v);
            // if (i == 2 and j == 2 and (t == 0 or t == 1))
            // {
            //     deb2(i1, j1);
            //     deb(t);
            // }
            // deb(t);

            // dp[i][j] = min(dp[i][j], t);
            dp[i][j] = min(dp[i][j], max(abs(v[i][j] - v[i1][j1]), t));
        }
        // nline;
    }
    // int mini = 0;
    // if (a.size() > 0)
    //     mini = *min_element(range(a));

    // dp[i][j] = max(dp[i][j], mini);
    visited[i][j] = 0;
    return dp[i][j];
}
void solve()
{
    vvi v = takematrixinput();
    printmatrix(v);

    vi l;
    int n = v.size(), m = v[0].size();
    vvb visited(n, vb(m, 0));
    vvi dp(n, vi(m, INT_MAX));
    dp[n - 1][m - 1] = 0;
    dfs(0, 0, l, visited, dp, v);
    debline(dp[0][0]);

    trav(dp)
    {
        trav2(x) print(y);
        nline;
    }
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