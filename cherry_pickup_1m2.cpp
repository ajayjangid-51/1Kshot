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

void fn(int i, int j, vvi &v, vvi &dp)
{
    if (dp[i][j] == -1)
        return;
    v[i][j] = 0;
    int i1 = i - 1, j1 = j - 1;
}

void solve()
{
    //----------------------------------------------------------------------------
    int n;
    cin >> n;
    vvi v(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    //----------------------------------------------------------------------------

    vvi dp(n, vi(n, -1));
    if (v[0][0] != -1)
        dp[0][0] = v[0][0];
    for (int j = 1; j < n; j++)
    {
        if (v[0][j] != -1 and dp[0][j - 1] != -1)
        {
            dp[0][j] = v[0][j] + dp[0][j - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] != -1 and dp[i - 1][0] != -1)
        {
            dp[i][0] = v[i][0] + dp[i - 1][0];
        }
    }

    //----------------------------------------------------------------------------

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[j][j] != -1)
            {
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                int maxi = max(up, left);
                if (maxi != -1)
                {
                    dp[i][j] = maxi + v[i][j];
                }
            }
        }
    }

    //----------------------------------------------------------------------------
    linebreak1;
    trav(dp)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;

    // fn(n - 1, n - 1, v, dp);

    //----------------------------------------------------------------------------
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
}
// so mtlb here there is caught in not take always maximum one..

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