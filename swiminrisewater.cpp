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
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }

    // apply dijkstra:-
    // vector<dist, i, j>
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({v[0][0], 0, 0});
    vector<vb> visited(n, vb(m, 0));
    visited[0][0] = 1;
    int mini = INT_MAX;
    // there in this dijkstra there is no need of dist[] array , because we can't reduce the dist[x] from any further node, (where as 'x' is already visited). because the edge between and x and any-furthernode is defined by thier node value difference. so in order to reduce the distanceof x the further should have value equal to value of node 'x' , so that is why there is no mean of trying to reduce the already visited node. that'swhy we didn't use dist[] array.
    while (!pq.empty())
    {
        vi f = pq.top();
        // if (f[1] == n - 1 and f[2] == m - 1)
        // {
        //     debline(f[0]);
        //     // return;
        // }
        pq.pop();
        for (int d = 0; d < 4; d++)
        {
            int i1 = f[1] + x[d];
            int j1 = f[2] + y[d];
            if (i1 >= 0 and j1 >= 0 and i1 < n and j1 < m and !visited[i1][j1])
            {

                // if (i1 != n - 1 and j1 != m - 1)
                int w = 0;
                // if (v[i1][j1] > v[f[1]][f[2]])
                if (v[i1][j1] > f[0])
                {
                    // w = v[i1][j1] - v[f[1]][f[2]];
                    w = v[i1][j1] - f[0];
                }
                if (i1 == n - 1 and j1 == m - 1)
                {
                    deb2(w, f[0]);
                    mini = min(w + f[0], mini);
                    continue;
                }
                visited[i1][j1] = 1;
                deb3("👉🏻", w, f[0]);
                pq.push({w + f[0], i1, j1});
            }
        }
    }
    debline(mini);
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