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
class dsu
{
private:
    /* data */
public:
    int n;
    vi justparent;
    vi size;
    dsu(int N)
    {
        n = N; // no.of individual nodes in graph:-
        justparent.resize(n);
        for (int i = 0; i < n; i++)
            justparent[i] = i;
        size.assign(n, 1);
        print("hello");
    }

    int find(int x)
    {
        while (justparent[x] != x)
            x = justparent[x];
        return x;
    }

    bool areinsame(int nodea, int nodeb)
    {
        return find(nodea) == find(nodeb);
    }

    void unite(int nodea, int nodeb)
    {
        int c1 = find(nodea);
        int c2 = find(nodeb);
        if (size[c1] < size[c2])
            swap(c1, c2);

        size[c1] += size[c2];
        justparent[c2] = c1;
    }

    int sizee(int component)
    {
        return size[component];
    }
};
int x[4] = {-1, +1, 0, 0};
int y[4] = {0, 0, -1, +1};
void dfs(int i, int j, vvi &grid, vvb &visited, dsu &d1)
{
    visited[i][j] = 1;
    int c0 = (i * grid[0].size()) + j;
    for (int d = 0; d < 4; d++)
    {
        int i1 = i + x[d];
        int j1 = j + y[d];
        if (i1 >= 0 and i1 < grid.size() and j1 >= 0 and j1 < grid[0].size() and !visited[i1][j1] and grid[i1][j1] == 1)
        {
            // get the componentnumber:-
            int c = (i1 * grid[0].size()) + j1;
            d1.unite(c0, c);
            dfs(i1, j1, grid, visited, d1);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vvb visited(n, vb(m, 0));

    //
    dsu d1((n * n));

    // now perform dfs from every unvisited "1" and make its component:-
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] and grid[i][j] == 1)
            {
                dfs(i, j, grid, visited, d1);
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                set<int> st;
                for (int d = 0; d < 4; d++)
                {
                    int i1 = i + x[d];
                    int j1 = j + y[d];
                    if (i1 >= 0 and i1 < grid.size() and j1 >= 0 and j1 < grid[0].size() and grid[i1][j1] == 1)
                    {
                        int c = (i1 * grid[0].size()) + j1;

                        st.insert(d1.find(c));
                    }
                }
                int sum = 0;
                trav(st)
                {
                    // print(x);
                    sum += d1.sizee(x);
                }
                // linebreak1;
                maxi = max(maxi, sum + 1);
            }
        }
    }

    linebreak1;
    trav(d1.size) print(x);
    linebreak1;
    debline(maxi);
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