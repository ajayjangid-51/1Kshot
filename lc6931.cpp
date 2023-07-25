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

long long fn(int i, vi &v, vi &odd, vi &even, vector<long long> &dp, int x, int p)
{
    if (i <= 0)
    {
        if (v[0] % 2 and p)
            return v[0];
        else if (v[0] % 2 == 0 and p == 0)
            return v[0];

        return v[0] - x;
    }
    if (dp[i] != -1)
        return dp[i];

    long long a = fn(odd[i - 1], v, odd, even, dp, x, 1);
    long long b = fn(even[i - 1], v, odd, even, dp, x, 0);
    int ans = 0;
    if (v[i] % 2)
        ans = max(a, b - x);
    else
        ans = max(a - x, b);

    return dp[i] = ans + v[i];
}

void solve()
{
    // vi v = {2, 3, 6, 1, 9, 2};
    vi v = {2, 4, 6, 8};

    int n = v.size();
    vi odd(n), even(n);
    odd[0] = even[0] = -1;
    if (v[0] % 2)
        odd[0] = 0;
    else
        even[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] % 2)
        {
            odd[i] = i;
            even[i] = even[i - 1];
        }
        else
        {

            even[i] = i;
            odd[i] = odd[i - 1];
        }
    }

    vector<long long> dp(n, -1);
    dp[0] = v[0];
    //
    for (auto x : odd)
        print(x);
    nline;
    for (auto x : even)
        print(x);
    nline;
    int x = 5;
    int ans = fn(n - 1, v, odd, even, dp, x, 2);
    debline(ans);
    for (auto x : dp)
    {
        print(x);
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