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
    int n, target;
    cin >> n >> target;

    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += v[i];
    }
    map<int, bool> m;
    map<int, int> cnt;
    m[v[n - 1]] = 1;
    m[-v[n - 1]] = 1;
    cnt[v[n - 1]] = 1;
    cnt[-v[n - 1]] = 1;

    debline(tsum);

    for (int i = n - 2; i >= -1; i--)
    {
        vector<int> tmp;
        map<int, int> cnt2;
        for (auto x : m)
        {
            if (cnt[x.first] != 0)
                tmp.push_back(x.first);
        }
        for (auto x : tmp)
        {
            print(x);
            if (v[i] + x >= -tsum and x + v[i] <= tsum)
            {

                m[x + v[i]] = 1;
                cnt2[x + v[i]] += cnt[x];
                // if (cnt2[x + v[i]] == 0)
                //     m.erase(x + v[i]);
            }
            if (-v[i] + x >= -tsum and x - v[i] <= tsum)
            {

                m[x - v[i]] = 1;

                cnt2[x - v[i]] += cnt[x];
                // if (cnt2[x - v[i]] == 0)
                //     m.erase(x - v[i]);
            }
        }
        nline;
        cnt = cnt2;
    }
    // trav(m) print()
    debline(cnt[target]);
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