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
int x[4] = {-1, +1, 0, 0};
int y[4] = {0, 0, -1, +1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vvi eft(n, vi(m, 110000));
    eft[0][0] = 0;
    priority_queue<vi, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    while (!pq.empty())
    {
        vi t = pq.top();
        pq.pop();
        if (t[1] == n - 1 and t[2] == m - 1)
        {
            debline(t[0]);
            break;
        }
        for (int d = 0; d < 4; d++)
        {
            int i1 = t[1] + x[d];
            int j1 = t[2] + y[d];
            if (i1 >= 0 and j1 >= 0 and i1 < n and j1 < m)
            {
                int diff = abs(v[i1][j1] - v[t[1]][t[2]]);
                int diff2 = max(diff, eft[t[1]][t[2]]);
                if (diff2 < eft[i1][j1])
                {
                    eft[i1][j1] = diff2;
                    pq.push({diff2, i1, j1});
                }
            }
        }
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