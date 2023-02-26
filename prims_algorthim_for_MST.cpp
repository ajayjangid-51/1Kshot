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

class disjointSetORUnionfindStructure
{
    // private:
public:
    vi parent;
    vi size;

    disjointSetORUnionfindStructure(int n) // 0 based indexing is considered.
    {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        size.assign(n, 1);
    }

    int find(int x) // x stands for any element of set.
    {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b); // means we are always considering set "a" as bigger one.
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }
};
void solve()
{
    vvi edgelist = {
        {1, 2, 3},
        {1, 5, 5},
        {2, 5, 6},
        {2, 3, 5},
        {5, 6, 2},
        {3, 4, 9},
        {6, 4, 7},
        {3, 6, 3}

    };
    int n = 6;
    vector<vvi> adj(n + 1);
    for (auto x : edgelist)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    disjointSetORUnionfindStructure dsu(n + 1); // bcoz in above graph 1based indexing is taken.
    // pq<pair<weight, othernode>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (auto x : adj[1])
    {
        pq.push({x[1], {1, x[0]}});
    }
    vector<bool> visited(n + 1, 0);
    int sum = 0;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> f = pq.top();
        pq.pop();
        int a = f.second.first, b = f.second.second, w = f.first;
        if (visited[b])
            continue;
        visited[a] = 1;
        if (dsu.find(a) != dsu.find(b))
        {
            dsu.unite(a, b);
            sum += w;
            for (auto x : adj[b])
            {
                pq.push({x[1], {b, x[0]}});
            }
        }
    }
    debline(sum);
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

/*
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
// #define size(v) v.size()
#define trav(v) for(auto x:v)
#define range(v) v.begin() , v.end()
class disjointSetORUnionfindStructure
{
    // private:
public:
    vi parent;
    vi size;

    disjointSetORUnionfindStructure(int n) // 0 based indexing is considered.
    {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        size.assign(n, 1);
    }

    int find(int x) // x stands for any element of set.
    {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b); // means we are always considering set "a" as bigger one.
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }
};
class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int n = V;
        disjointSetORUnionfindStructure dsu(n);
        // code here  disjointSetORUnionfindStructure dsu(n + 1); // bcoz in above graph 1based indexing is taken.
    // pq<pair<weight, othernode>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (auto x : adj[0])
    {
        pq.push({x[1], {0, x[0]}});
    }
    vector<bool> visited(n + 1, 0);
    int sum = 0;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> f = pq.top();
        pq.pop();
        int a = f.second.first, b = f.second.second, w = f.first;
        if (visited[b])
            continue;
        visited[a] = 1;
        if (dsu.find(a) != dsu.find(b))
        {
            dsu.unite(a, b);
            sum += w;
            for (auto x : adj[b])
            {
                pq.push({x[1], {b, x[0]}});
            }
        }
    }
    return sum;
    }
};
 */