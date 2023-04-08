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
    int n, m;
    cin >> n >> m;
    vi c(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    nline;
    trav(c) print(x);
    nline;
    trav(w) print(x);
    nline;

    int tsum = 0;
    trav(c) tsum += x;
    debline(tsum);

    vb dp(tsum + 1, 0);
    dp[0] = 1;
    vi remW(tsum + 1, -1);
    remW[0] = m;

    for (int i = n - 1; i >= 0; i--)
    {
        vi p;
        // vi rem2(tsum + 1, -1);
        vi rem2 = remW;
        for (int j = 0; j < dp.size(); j++)
        {
            if (dp[j])
            {
                p.push_back(j);
            }
        }
        trav(p)
        {
            // print(x);
            if (remW[x] - w[i] >= 0)
            {
                // if (x + c[i] <= tsum)
                // {

                dp[x + c[i]] = 1;
                // remW[x + c[i]] = max(remW[x + c[i]], remW[x] - w[i]);
                rem2[x + c[i]] = max(rem2[x + c[i]], remW[x] - w[i]);

                // }
            }
        }
        remW = rem2;
        // linebreak1;
    }

    nline;
    deb("hi");
    trav(dp) print(x);
    nline;
    trav(remW) print(x);
    nline;

    int maxx = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        // if (remW[i] != -1)
        // {
        //     maxx = max(maxx, i);
        // }
        if (dp[i])
            maxx = i;
    }
    debline(maxx);
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