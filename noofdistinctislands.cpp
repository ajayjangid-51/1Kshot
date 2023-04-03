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
void inputMatrix(int &n, int &m, vvi &M)
{
    cin >> n >> m;
    M.resize(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
}
int x[4] = {-1, +1, 0, 0};
int y[4] = {0, 0, -1, +1};
void solve()
{
    int n, m;
    vvi v;
    inputMatrix(n, m, v);
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    vvb visited(n, vb(m, 0));

    set<vector<pii>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] and v[i][j] == 1)
            {
                vector<pii> a;
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = 1;
                a.push_back({0, 0});
                while (!q.empty())
                {
                    pii f = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int i1 = f.first + x[d], j1 = f.second + y[d];
                        if (i1 >= 0 and j1 >= 0 and i1 < n and j1 < m and !visited[i1][j1] and v[i1][j1] == 1)
                        {
                            visited[i1][j1] = 1;
                            q.push({i1, j1});
                            a.push_back({i1 - i, j1 - j});
                        }
                    }
                }
                deb2(i, j);
                s.insert(a);
            }
        }
    }
    trav(s)
    {
        trav(x)
        {
            print(x.first), print(','), print(x.second);
        }
        nline;
    }
    debline(siz(s));
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