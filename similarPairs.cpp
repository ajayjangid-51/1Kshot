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
void solve()
{
    vi A = {1, 2, 1, 3, 1, 4};
    int n = A.size();
    map<int, vector<int>> m;

    for (int i = 0; i < A.size(); i++)
    {
        vector<int> v(n, 0);
        m[A[i]] = v;
    }
    // vector<int> t2(n, 1);
    m[A[0]] = vector<int>(n, 1);

    for (int i = 1; i < A.size(); i++)
    {
        vector<int> v = m[A[i]];
        int tt = m[A[i]][i - 1] + 1;
        for (int j = i; j < n; j++)
        {
            v[j] = tt;
        }
        m[A[i]] = v;
    }
    trav(m)
    {
        trav2(x.second) print(y);
        nline;
    }
    int ans = 0;
    int B = 2;
    for (int i = 0; i < n; i++)
    {
        int t3;
        if (i + B < n)
            t3 = m[A[i]][i + B];
        else
            t3 = m[A[i]][n - 1];

        int tt = t3 - m[A[i]][i];
        deb(tt);
        if (tt > 0)
            ans += tt;
    }
    debline(ans);
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