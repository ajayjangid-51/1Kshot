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

void fn(int r, int n, vector<vector<string>> &ans, vector<string> &v, vector<int> &check)
{
    if (r == n)
    {
        ans.push_back(v);
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!check[c] and !check[n + r + c] and !check[(4 * n - 2) + c - r])
        {
            check[c] = check[n + r + c] = check[((4 * n) - 2) + c - r] = 1;
            v[r][c] = 'Q';
            fn(r + 1, n, ans, v, check);
            check[c] = check[n + r + c] = check[((4 * n) - 2) + c - r] = 0;
            v[r][c] = '.';
        }
    }
}
void solve()
{
    int n = 4;
    vector<vector<string>> ans;
    string t;
    for (int i = 0; i < n; i++)
    {
        t.push_back('.');
    }
    // vector<int> check(n + ((4 * n) - 2), 0);
    vector<int> check(((5 * n) - 2), 0);
    vector<string> v(n, t);
    fn(0, n, ans, v, check);

    trav(ans)
    {
        trav2(x) print(y);
        nline;
    }
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