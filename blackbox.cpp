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

/* 0️⃣ */
/*take graph input by its no.ofnodes, no.ofedges, and its edgelist and form adjlist of graph. */
// void getgraphinput()
// take input undirected weighted graph
void takegraphinput(int &n, int &e, vector<vvi> &adj)
{
    // "n" means no.ofnodes and "e" stands for no.ofedges and here nodes are indexed zero-based.
    cin >> n >> e;
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        // adj[b].push_back({a, w});
    }
    print("-:👉🏻graph Adjlist👈🏻:-");
    linebreak1;
    for (int i = 0; i < n; i++)
    {
        print(i), print("-");
        trav(adj[i]) print("{"), print(x[0]), print(','), print(x[1]), print('}'), print(",");
        nline;
    }
    linebreak1;
}

// take input simple directed graph:-
void inputgraph(int &n, int &e, vvi &adj)
{
    // 0 based indexing nodes.
    print("input the no. of nodes and no.of edges and then edges");
    cin >> n >> e;
    adj.resize(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

// tip:- we can make class templates... as based upon on the problem type, paradigmtype, input type.. etc..etc..
// take input matrix:-
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

// print matrix:
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

// trav matrix
void travMatrix(int &n, int &m, vvi &v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        }
    }
}

// 4direction in matrix:
void fourdirections()
{
    //          up down left right
    //         ⬆️⬇️⬅️➡️
    //          0 1  2 3
    // x show affect in horizontal if some move is taken and here -1,+1 are denoting change in rownumber and column number.
    int x[4] = {-1, +1, 0, 0};
    int y[4] = {0, 0, -1, +1}; // affect in vertical
}
// 8direction in matrix:
void eightDirection()
{
    //          up down left right
    //          ⬆️⬇️⬅️➡️ ↖️↗️ ↙️↘️
    //           0 1  2 3   4 5   6 7
    int x[8] = {-1, +1, 0, 0, -1, +1, -1, +1};
    int y[8] = {0, 0, -1, +1, -1, -1, +1, +1};
}

// dsu disjoint set union find structure:-
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
        noofcomponents = N;
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

int main()
{
    io_faster
    file();

    return 0;
}