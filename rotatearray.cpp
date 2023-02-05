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
class Solution
{
public:
    void rotate(vector<int> &v, int k)
    {
        int n = v.size();
        if (k == n)
            return;
        if (k > n)
            k = k % n;

        int t = v[0];
        int i = k;
        int f = 0;
        int cnt = 0;
        while (cnt < n - 1)
        {
            cnt++;
            int d = v[i];
            v[i] = t;
            t = d;
            i = (i + k) % n;
            if (i == f)
            {
                v[i] = t;
                f++;
                i = f;
            }
        }
    }
};
void solve()
{
    vi v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int i = k;
    int t = v[0];
    int n = v.size();
    while (i)
    {
        int d = v[i];
        v[i] = t;
        t = d;
        i = (i + k) % n;
    }
    v[0] = t;
    // print("hi");
    linebreak1;
    trav(v) print(x);
    linebreak1;
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