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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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

// pure recursive + memoization solution.
int fn(int n, int k, int sell, vector<int> &v, vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 0;
    if (n == 1 and sell)
        return 0;
    if (n == 1 and !sell)
        return -v[0];
    if (dp[n][k][sell] != -1)
        return dp[n][k][sell];
    if (sell)
    {
        return dp[n][k][sell] = max(v[n - 1] + fn(n - 1, k, 0, v, dp), max(fn(n - 1, k, 0, v, dp), fn(n - 1, k, 1, v, dp)));
    }
    else
    {
        return dp[n][k][sell] = max(-v[n - 1] + fn(n - 1, k - 1, 1, v, dp), fn(n - 1, k, 0, v, dp));
    }
}

void solve()
{
    vector<int> v = {3, 2, 6, 5, 0, 3};
    int n = v.size();
    int k = 2;
    // vector<vector<vector<int>>> dp(n+1 , )
    map<vector<int>, int> mp;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    int ans = fn(n, k, 1, v, dp); // 1 mtlb "sell" and 0 mtlb "buy".
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