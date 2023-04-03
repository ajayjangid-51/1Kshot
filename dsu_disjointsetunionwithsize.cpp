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
        // cin >> n; // no.of individual nodes in graph:-
        n = N;
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

    bool same(int nodea, int nodeb)
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

void solve()
{
    int n;
    cin >> n;
    dsu d1(n);
    int e;
    cin >> e;
    vvi edgelist;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edgelist.push_back({a, b});
    }
    int cnt = 0;
    int cmps = d1.n;
    trav(edgelist)
    {
        if (d1.same(x[0], x[1]))
        {
            cnt++;
        }
        else
        {
            d1.unite(x[0], x[1]);
            cmps--;
        }
    }
    debline(cnt);
    debline(cmps);
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