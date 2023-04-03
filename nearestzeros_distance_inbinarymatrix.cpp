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
    vvi M;
    inputMatrix(n, m, M);
    linebreak1;

    trav(M)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;

    // this bfs(searching for zeroes from every one) approach is not efficient means it will take (n2*n2)time
    // now if bfs-dp(mtlb when doing bfs then if any node is visited first then we will take its answer) is used but we can't perform dpstoring in bfs bcoz we have move in backward(reverse) direction, so mtlb childanswer can't be given to its parent.
    // so the final approach is we will do opposite of first approach that we will search of "1" from "zeroes" so means if we found "1" then it is sure ki for that "1" this "0" is nearest one.. and so on...

    vvi ans(n, vi(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
                ans[i][j] = 0;
            else
            {
                // deb2(i, j);
                queue<pii> q;
                vvi dist(n, vi(m, -1));
                dist[i][j] = 0;
                ans[i][j] = 1000;
                q.push({i, j});
                bool b = 0;
                while (!q.empty())
                {
                    if (b)
                        break;
                    int i0 = q.front().first;
                    int j0 = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int i1 = i0 + x[d];
                        int j1 = j0 + y[d];
                        if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < m)
                        {
                            if (ans[i1][j1] != -1)
                            {
                                // deb3("👉🏻", i1, j1);

                                if (ans[i0][j0] == -1)
                                {

                                    ans[i0][j0] = ans[i1][j1] + 1;
                                }
                                else
                                    ans[i0][j0] = min(ans[i0][j0], ans[i1][j1] + 1);
                                // deb(ans[i1][j1]);
                                // deb(ans[i][j]);
                                // nline;
                            }
                            else if (dist[i1][j1] == -1)
                            {

                                dist[i1][j1] = dist[i0][j0] + 1;
                                if (M[i1][j1] == 0)
                                {
                                    b = 1;
                                    // ans[i0][j0] = dist[i1][j1];
                                    ans[i][j] = dist[i1][j1];
                                    // deb2(i1, j1);
                                    // debline(ans[i][j]);
                                    break;
                                }

                                q.push({i1, j1});
                            }
                            ans[i][j] = min(ans[i][j], ans[i1][j1]);
                        }
                    }
                }
            }
        }
    }
    linebreak1;
    trav(ans)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
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