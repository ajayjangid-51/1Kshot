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
    int n;
    cin >> n;
    vi v(n);
    for (auto &x : v)
        cin >> x;
    linebreak1;
    trav(v) print(x);
    vector<vector<pii>> dp(n + 1, vector<pii>(n + 1, {0, 0}));

    // fill base case:-
    // if (n == 1 element) then return {v[n], 0};
    // if (n == 2 element) then return {max(v[n-1] , v[n]) , v[n-1]*v[n]}
    for (int j = 1; j <= n; j++)
    {
        for (int i = j; i >= 1; i--)
        {
            if (i == j)
            { // if only 1 element
                dp[i][j] = {v[i - 1], 0};
            }
            else if (i + 1 == j)
            { // if 2 elements
                dp[i][j] = {max(v[i - 1], v[j - 1]), v[i - 1] * v[j - 1]};
            }
            else
            {
                // int ans = INT_MAX;
                // pii p = {-1, 0};
                int maxx = -1;
                int ans = INT_MAX;

                for (int k = 0; k < (j - i - 1); k++)
                {
                    // means the i to j is breaked into left(i to k) and right(k+1 to j);
                    // pii l = {i, i + k};
                    // pii r = {i + k + 1, j};
                    // debpair(l);
                    // debpair(r);
                    // nline;
                    pii left = dp[i][i + k];
                    pii right = dp[i + k + 1][j];
                    pii p = {max(left.first, right.first), {(left.first * right.first) + left.second + right.second}};
                    if (p.second < ans)
                    {
                        ans = p.second;
                        maxx = p.first;
                    }
                }
                dp[i][j] = {maxx, ans};
            }
        }
    }

    debline(dp[1][n].second);
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