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
    // vvi A = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {17, 20}};
    // vvi A = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vvi A = {{1, 4}, {4, 5}};
    sort(A.begin(), A.end());
    vvi ans;
    pii t;
    bool pmt = 1;
    trav(A)
    {
        // debpair(t);
        print(x[0]), print(x[1]);
        linebreak1;
        if (!pmt)
        {
            if (x[0] >= t.first and x[0] <= t.second)
            {
                if (t.second <= x[1])
                {
                    t.second = x[1];
                }
            }
            else
            {
                ans.push_back({t.first, t.second});
                t = {x[0], x[1]};
                // pmt = 1;
            }
        }
        else
        {
            t = {x[0], x[1]};
            debpair(t);

            pmt = 0;
        }
    }
    // deb(pmt);
    if ((*ans.rbegin())[0] != t.first)
        ans.push_back({t.first, t.second});
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