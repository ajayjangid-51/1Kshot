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
    int noofcomponents;
    int xtraedges = 0;
    vi justparent;
    vi size;

    dsu(int N, int C)
    {
        n = N; // no.of individual nodes in graph:-
        noofcomponents = C;
        justparent.resize(n);
        for (int i = 0; i < n; i++)
            justparent[i] = i;
        size.assign(n, 1);
    }

    int find(int x)
    {
        while (justparent[x] != x)
            x = justparent[x];
        return x;
    }

    bool areinsame(int nodea, int nodeb)
    {
        return (find(nodea) == find(nodeb));
    }

    void unite(int nodea, int nodeb)
    {
        // deb2(nodea, nodeb);
        if (areinsame(nodea, nodeb))
        {
            xtraedges++;
            return;
        }

        noofcomponents--;
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
void solve()
{
    int n, m, q0;
    cin >> n >> m >> q0;
    vvi q;
    for (int i = 0; i < q0; i++)
    {
        int a, b;
        cin >> a >> b;
        q.push_back({a, b});
    }
    vvi mat(n, vi(m, 0));
    dsu d1(n * m, -1);
    int cnt = 0;
    vector<int> ans;
    for (auto z : q)
    {
        cnt++;
        int i = z[0], j = z[1];
        int c0 = (i * m) + j;
        mat[i][j] = 1;
        // deb3("👉🏻", i, j);
        for (int d = 0; d < 4; d++)
        {
            int i1 = i + x[d], j1 = j + y[d];
            // deb3("❤️", i1, j1);
            if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < m and mat[i1][j1] == 1)
            {
                int c = (i1 * m) + j1;
                if (d1.areinsame(c0, c))
                {
                    // deb2(i1, j1);
                    continue;
                    // cnt--;
                }
                // else
                // {
                d1.unite(c0, c);
                cnt--;
                // }
            }
            // else
            // cnt--;
        }
        // deb(cnt);
        // linebreak1;
        ans.push_back(cnt);
    }
    // linebreak1;
    trav(ans) print(x);
    nline;
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
