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
int fn(int i, int j, vi &v, int t)
{
    print(i), print(j), nline;

    if (i > j)
        return -1;
    int mid = (i + j) / 2;
    debline(v[mid]);
    if (t == v[mid])
    {
        return mid;
    }
    if (t < v[mid])
    {
        if (t >= v[i] or t <= v[mid - 1])
        {
            return fn(i, mid - 1, v, t);
        }
        else
        {
            return fn(mid + 1, j, v, t);
        }
    }
    else
    {
        if (t <= v[j] or t >= v[mid + 1])
        {
            return fn(mid + 1, j, v, t);
        }
        else
        {
            return fn(i, mid - 1, v, t);
        }
    }
}
void solve()
{
    // vi v = {4, 5, 6, 7, 0, 1, 2};
    //      0  1  2  3  4  5  6  7
    vi v = {4, 5, 6, 7, 8, 1, 2, 3};
    int t = 8;
    int inx = fn(0, v.size() - 1, v, t);
    debline(inx);
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