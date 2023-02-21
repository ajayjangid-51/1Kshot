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
    // so floydwarshall algorithm apn ek 2darray banateh hai joki contains the information about shortest distances between every nodes. and firstly the distances are assigned as the direct edge between the nodes and then we simply take all nodes(one by one) as a intermediate node inbetween the paths of every node. mtlb one by one we will try to include all nodes betwen then path of 2 nodes and then check for the reduction in the distance.
    // on round1 the node1 will be new intermediate node from now on between all the paths but point to be notes if the intermedidate node reduce the distance the only we will consider that node as intermediate node in that path otherwise it is obvious not included:-

    // graph edgelist:-
    vvi edgelist = {
        {2, 3, 2},
        {3, 4, 7},
        {4, 1, 9},
        {2, 1, 5},
        {4, 5, 2},
        {1, 5, 1}};
    int nodes = 5; // 1based indexingvalue
    // so first create 2darray which represents edgeweight between node (i,j);
    vvi v(nodes + 1, vi(nodes + 1, 1e8));
    for (auto x : edgelist)
    {
        v[x[0]][x[0]] = 0;
        v[x[1]][x[1]] = 0;
        v[x[0]][x[1]] = x[2];
        v[x[1]][x[0]] = x[2];
    }
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 0; i <= nodes; i++)
        {
            for (int j = 0; j < nodes + 1; j++)
            {
                v[i][j] = min(v[i][j], (v[i][k] + v[k][j]));
            }
        }
    }
    linebreak1;
    trav(v)
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
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}