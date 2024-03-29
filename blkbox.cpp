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

class Graph1
{

    // 1.take graph in input.
    void takeGraphInInput()
    {
        int n, e;
        cin >> n >> e;
        vvi edges;
        vvi adj(n);
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, b});
            adj[a].push_back(b);

            // for undirected:-
            // adj[b].push_back(a);
        }
        for (int i = 0; i < e; i++)
        {
            cout << edges[i][0] << ' ' << edges[i][1] << endl;
        }
        for (int i = 0; i < n; i++)
        {
            print(i), print(" - ");
            trav(adj[i]) print(x);
            nline;
        }
    }
};
//
class Graph
{
private:
    int n;

    // graph representations:-
    vector<vector<int>> adj;   // adjacency list
    vector<vector<bool>> mat;  // adjacency matrix
    vector<vector<int>> edges; // edgelist
    vector<bool> visited;
    vector<bool> fullvisited;

public:
    Graph(int noOfNodes)
    {
        // "n" is per 0-based indexing
        n = noOfNodes;
        adj.resize(n);
        mat.resize(n, vector<bool>(n, 0));
    }

    // void create

    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {
        if (visited[node])
            return;
        visited[node] = 1;
        ans.push_back(node);
        for (auto x : adj[node])
        {
            dfs(x, adj, visited, ans);
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, 0);
        vector<int> ans;
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                int front = q.front();
                q.pop();
                ans.push_back(front);
                for (auto x : adj[front])
                {
                    if (visited[x])
                        continue;
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

void solve()

{
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