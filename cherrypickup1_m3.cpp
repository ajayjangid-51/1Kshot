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

    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
    dp[0][0][0][0] = v[0][0];

    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            if (v[i1][j1] == -1)
                continue;
            for (int j2 = 0; j2 < n; j2++)
            {
                int i2 = (i1 + j1) - j2;
                if (i2 < 0 or i2 >= n)
                    continue;
                // deb(i2);
                if (v[i2][j2] == -1)
                    continue;
                if (i1 == 0 and j1 == 0 and i2 == 0 and j2 == 0)
                {
                    continue;
                }
                // print("hi");
                int maxi = -1;
                // now we have four options : -
                for (int d1 = -1; d1 <= 0; d1++)
                {
                    int j3 = j1 + d1;
                    int i3 = i1;
                    if (d1 == 0)
                        i3 = i1 - 1;
                    for (int d2 = -1; d2 <= 0; d2++)
                    {
                        int value = 0;
                        int j4 = j2 + d2;
                        int i4 = i2;
                        if (d2 == 0)
                        {
                            i4 = i2 - 1;
                        }

                        if (i1 == i2 and j1 == j2)
                        {
                            value += v[i1][j1];
                        }
                        else
                        {
                            value += (v[i1][j1] + v[i2][j2]);
                        }

                        if (j3 >= 0 and i3 >= 0 and j4 >= 0 and i4 >= 0 and v[i3][j3] != -1 and v[i4][j4] != -1)
                        {
                            value += dp[i3][j3][i4][j4];
                        }
                        else
                        {
                            value += -1e8;
                        }
                        // deb(value);
                        maxi = max(maxi, value);
                    }
                }

                dp[i1][j1][i2][j2] = maxi;
            }
        }
    }

    linebreak1;
    debline(dp[n - 1][n - 1][n - 1][n - 1]);
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