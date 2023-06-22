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

void solve()
{
    int n, t;
    cin >> n >> t;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    linebreak1;

    int tsum = accumulate(range(v), 0);
    deb(tsum);
    // create dpstore:
    vvi dp(n + 1, vi((2 * tsum) + 1, 0));
    deb2(dp.size(), dp[0].size());
    dp[0][tsum] = 1;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < dp[0].size(); j++)
        {
            int target = j - tsum;
            // int ans = 0;
            // i have options that i can +ive or -ive
            // +ive taken
            int reqtarget = target - v[i - 1];
            int plus = 0;
            if (reqtarget >= -tsum and reqtarget <= tsum)
            {
                plus = dp[i - 1][tsum + reqtarget];
            }
            // -ive taken
            reqtarget = target + v[i - 1];
            int minus = 0;
            if (reqtarget >= -tsum and reqtarget <= tsum)
            {
                minus = dp[i - 1][tsum + reqtarget];
            }
            dp[i][j] = plus + minus;
        }
    }

    linebreak1;
    trav(dp)
    {
        trav2(x) print(y);
        nline;
    }
    debline(dp[n][t + tsum]);
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

class Solution
{
public:
    int findTargetSumWays(vector<int> &v, int t)
    {
        int n = v.size();
        int tsum = accumulate(range(v), 0);
        if (t > tsum or t < -tsum)
            return 0;
        // deb(tsum);
        // create dpstore:
        vvi dp(n + 1, vi((2 * tsum) + 1, 0));
        // deb2(dp.size(), dp[0].size());
        dp[0][tsum] = 1;
        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j < dp[0].size(); j++)
            {
                int target = j - tsum;
                // int ans = 0;
                // i have options that i can +ive or -ive
                // +ive taken
                int reqtarget = target - v[i - 1];
                int plus = 0;
                if (reqtarget >= -tsum and reqtarget <= tsum)
                {
                    plus = dp[i - 1][tsum + reqtarget];
                }
                // -ive taken
                reqtarget = target + v[i - 1];
                int minus = 0;
                if (reqtarget >= -tsum and reqtarget <= tsum)
                {
                    minus = dp[i - 1][tsum + reqtarget];
                }
                dp[i][j] = plus + minus;
            }
        }

        // linebreak1;
        // trav(dp)
        // {
        //     trav2(x) print(y);
        //     nline;
        // }
        return (dp[n][t + tsum]);
    }
};