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
#define size(x) x.size()
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

void solve()
{
    // so in bellman we will process the graph in its initial edgelist-representation only.
    // so first edgelist with weight:-
    vvi edgelist = {
        {1, 2, 5},
        {1, 4, 7},
        {1, 3, 3},
        {2, 4, 3},
        {3, 4, 1},
        {2, 5, 2},
        {4, 5, 2}};
    int S = 1;

    int nodes = 5; // 1based indexing-value nodes.
    vi dist(nodes + 1, 1e8);
    dist[S] = 0;
    bool isnegativelengthcyclepresent = 0;
    for (int i = 0; i < nodes; i++)
    {
        for (auto x : edgelist)
        {
            int a = x[0], b = x[1], w = x[2];
            if (i == nodes - 1)
            {
                if (dist[a] + w < dist[b])
                {
                    isnegativelengthcyclepresent = 1;

                    break;
                }
            }

            dist[b] = min(dist[b], dist[a] + w);
        }
    }

    linebreak1;
    trav(dist) print(x);
    linebreak1;
}

int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}