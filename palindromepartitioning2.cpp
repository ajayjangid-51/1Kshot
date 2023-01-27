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
// int mini = INT_MAX;
int fn(string &st, int s, int e, vvi &dp, int cut, vi &dp2)
{

    if (s > e)
    {
        // return dp2[e] = cut;
        return 0;
        // return cut;
        // mini = min(mini, cut);
        // return;
    }
    if (dp2[e] != -1)
    {
        return dp2[e];
    }
    // if (dp2[s] != -1)
    // {
    //     return dp2[s];
    //     // mini = min(mini, dp2[s]);
    //     // return;
    // }

    // for (int i = s; i <= e; i++)
    for (int i = e; i >= s; i--)
    {
        if (dp[i][e])
        {
            // dp2[s] = min(dp2[s], fn(st, s, i - 1, dp, cut + 1, dp2) + 1);
            dp2[i] = min(fn(st, s, i - 1, dp, cut + 1, dp2) + 1, dp2[i - 1]);
        }
    }
    return dp2[e];
}
void solve()
{
    // string s("aabaebe");
    // string s("aab");
    string s("ababababababababababababcbabababababababababababa");
    int n = s.size();
    vvi dp(n, vi(n, 1));
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }
    vi dp2(n);
    // dp2[0] = INT_MAX;
    // dp2[n - 1] = 0;
    // trav(dp)
    // {
    //     trav2(x) print(y);
    //     nline;
    // }
    // int ans = fn(s, 0, n - 1, dp, 0, dp2);
    // debline(ans);

    for (int i = n - 1; i >= 0; i--)
    {
        dp2[i] = n - i - 1;
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
            {
                if ((j == n - 1))
                    dp2[i] = 0;
                else
                    dp2[i] = min(dp2[i], 1 + dp2[j + 1]);
            }
        }
    }
    debline(dp2[0]);
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