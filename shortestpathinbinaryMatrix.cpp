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
tuple<int, int, vvi> takematrixinput()
{
    int n, m;
    cin >> n >> m;
    vvi mat(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    return {n, m, mat};
}
void printmatrix(vvi &mat)
{
    int row = mat.size();
    if (row == 0)
    {
        print("empty matrix:");
        return;
    }
    int column = mat[0].size();
    nline;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            print(mat[i][j]);
        }
        nline;
    }
}

//          up down left right
//          ⬆️⬇️⬅️➡️ ↖️↗️ ↙️↘️
//           0 1  2 3   4 5   6 7
int x[8] = {-1, +1, 0, 0, -1, +1, -1, +1};
int y[8] = {0, 0, -1, +1, -1, -1, +1, +1};

void solve()
{
    int n, m;
    vvi v;
    tie(n, m, v) = takematrixinput();
    printmatrix(v);
    pii s, dd;
    cin >> s.first >> s.second >> dd.first >> dd.second;

    // simply perfrom bfs:-
    vvb visited(n, vb(m, 0));
    queue<vi> q;
    q.push({s.first, s.second, 0});
    bool bb = 0;

    while (!q.empty())
    {
        vi f = q.front();
        q.pop();
        int i = f[0], j = f[1];
        visited[i][j] = 1;

        for (int d = 0; d < 8; d++)
        {
            int i1 = i + x[d];
            int j1 = j + y[d];
            if (i1 >= 0 and i1 < v.size() and j1 >= 0 and j1 < v[0].size() and v[i1][j1] == 1)
            {
                if (i1 == dd.first and j1 == dd.second)
                {
                    deb("hi");
                    bb = 1;
                }
                if (!visited[i1][j1])
                {

                    // deb(v[i1][j1]);
                    v[i1][j1] = f[2] + 1;

                    q.push({i1, j1, f[2] + 1});
                }
            }
        }
    }
    if (bb == 0)
        debline("-1");
    debline(v[dd.first][dd.second]);
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