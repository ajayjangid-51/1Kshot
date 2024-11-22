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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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
    int n;
    vi rpt;
    vi sz;
    int c;

public:
    dsu(int nodes)
    {
        n = nodes;
        for (int i = 0; i < n; i++)
        {
            rpt.push_back(i);
            sz.push_back(1);
        }
    }
    //
    int findrpt(int node)
    {
        // deb(rpt[node]);
        while (rpt[node] != node)
        {
            node = rpt[node];
        }
        return node;
    }
    void unite(int nodea, int nodeb)
    {
        if (findrpt(nodea) == findrpt(nodeb))
            return;
        int sizea = sz[findrpt(nodea)];
        int sizeb = sz[findrpt(nodeb)];
        if (sizea > sizeb)
            swap(nodea, nodeb);
        rpt[findrpt(nodea)] = rpt[findrpt(nodeb)];
    }
};

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    trav(edges)
    {
        trav2(x) print(y);
        nline;
    }
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         {
        if(a[2]<b[2]) return 1;
        return 0; });
    linebreak1;
    trav(edges)
    {
        trav2(x) print(y);
        nline;
    }
    int ans = 0;
    dsu d(n);
    for (auto x : edges)
    {
        int a = x[0], b = x[1], w = x[2];
        if (d.findrpt(a) != d.findrpt(b))
        {
            ans += w;
            d.unite(a, b);
        }
    }
    debline(ans);
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