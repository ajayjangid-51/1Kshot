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

    queue<vi> q;
    vvb visited(n, vb(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
        }
    }
    vvi ans(n, vi(m, 0));
    while (!q.empty())
    {
        vi f = q.front();
        q.pop();
        ans[f[0]][f[1]] = f[2];
        for (int d = 0; d < 4; d++)
        {
            int i1 = f[0] + x[d];
            int j1 = f[1] + y[d];
            if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < m and !visited[i1][j1]) // yaha visited ka mtlb hai ki voh node({i1,j1}) phle hi approach/reach ho chuka hai, toh mtlb sure hai ki voh node apne se nearer distance pe hai, toh mtlb usko apn chedenge nhi q ki he is already at minimum distance.
            // notepoint:- unweighted graph meh bfs meh visited hone ka mtlb voh node phle hi kisi other se reached hochuka hai , mtlb voh node kisi other node apn se nearer distance pe hai, so toh isiliy apn visited node ko vapis visit nhi krtehh if we are in a search of shortest distances/path ('/' i.e "or").
            {
                visited[i1][j1] = 1;
                q.push({i1, j1, f[2] + 1});
            }
        }
    }
    linebreak1;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}