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
    //           A   B   C   D
    // vi v = {40, 20, 30, 10, 30};
    vi v = {10, 30, 5, 60};
    int n = siz(v) - 1;
    vvi dp(n, vi(n, INT_MAX)); // where dp[i][j] stores the no.of-multiplicaton of multiplying the matrices from itoj.
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < (n - l); i++)
        {
            int j = i + l;
            if (l == 0)
            {
                // dp[i][j] = v[i] * v[i + 1];
                dp[i][j] = 0;
            }
            else
            {

                for (int k = i; k <= (j - 1); k++)
                {
                    int p = dp[i][k] + dp[k + 1][j];
                    // p += v[i - 1] * v[k] * v[j];
                    p += v[i] * v[k + 1] * v[j + 1];
                    dp[i][j] = min(dp[i][j], p);
                }
            }
        }
    }
    debline(dp[0][n - 1]);
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