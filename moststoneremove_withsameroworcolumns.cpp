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

    dsu(int N)
    {
        n = N; // no.of individual nodes in graph:-
        noofcomponents = 500;
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
        deb2(nodea, nodeb);
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

void solve()
{

    int n = 0, m = 0;
    vvi v;
    int a, b;
    while (cin >> a >> b)
    {
        // n = max(n, max(a, b));
        n = max(n, a);
        m = max(m, b);
        v.push_back({a, b});
    }
    vvi mat(n + 1, vi(m + 1, 0));
    trav(v)
    {
        mat[x[0]][x[1]] = 1;
    }
    // deb(n);
    deb2(n, m);
    dsu d1((n + 1) * (m + 1));
    for (int i = 0; i < v.size(); i++)
    {
        int c0 = v[i][0] * (m + 1) + v[i][1];

        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i][0] == v[j][0] or v[i][1] == v[j][1])
            {
                int c = v[j][0] * (m + 1) + v[j][1];
                d1.unite(c0, c);
            }
        }
    }
    // linebreak1;
    // trav(d1.size) print(x);
    // linebreak1;
    // deb(d1.noofcomponents);
    print("hello");
    int ans = 0;
    for (int i = 0; i < d1.justparent.size(); i++)
    {
        int t = i;
        int i1 = i / (m + 1);
        int j1 = i % (m + 1);
        // deb3(i, i1, j1);
        if (mat[i1][j1] == 1 and d1.justparent[i] == i)
        {
            ans += (d1.size[i] - 1);
        }
    }
    print("bye");
    debline(ans);
    debline(500 - d1.noofcomponents);
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