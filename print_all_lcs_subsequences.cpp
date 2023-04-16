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
void dfs(int i, int j, string s, string &s1, string &s2, vvi &dp, set<string> &ans, int cnt)
{
    if (cnt == 0)
    {
        ans.insert(s);
        return;
    }
    if (i >= s1.size() or j >= s2.size())
        return;

    // if (i == s1.size() or j == s2.size())
    // {
    //     deb(s);
    //     ans.push_back(s);
    //     return;
    // }
    if (s1[i] == s2[j])
    {
        dfs(i + 1, j + 1, s + s1[i], s1, s2, dp, ans, cnt - 1);
    }
    else
    {
        int maxi = max(dp[i + 1][j], dp[i][j + 1]);
        if (maxi == dp[i + 1][j])
        {
            dfs(i + 1, j, s, s1, s2, dp, ans, cnt);
        }
        if (maxi == dp[i][j + 1])
        {
            dfs(i, j + 1, s, s1, s2, dp, ans, cnt);
        }
    }
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vvi dp(n + 1, vi(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    linebreak1;
    trav(dp)
    {
        trav2(x) print(y);
        nline;
    }

    //
    set<string> ans;
    int cnt = dp[0][0];
    dfs(0, 0, "", s1, s2, dp, ans, cnt);
    linebreak1;
    trav(ans) print(x);
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