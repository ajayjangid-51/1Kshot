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

void solve()
{
    vvi adj = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    trav(adj)
    {
        trav2(x) print(y);
        nline;
    }
    // now reverse the edges:-
    int n = adj.size();
    vvi adj2(n);
    queue<int> q;

    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].size() == 0)
            q.push(i);
        trav(adj[i])
        {
            adj2[x].push_back(i);
        }
    }
    linebreak1;
    vi indeg(n, 0);
    trav(adj2)
    {
        trav2(x) indeg[y]++;
        // nline;
    }
    linebreak1;
    trav(indeg) print(x);
    linebreak1;

    vi ans;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto x : adj2[f])
        {
            indeg[x]--;
            if (indeg[x] == 0)
                q.push(x);
        }
    }
    sort(range(ans));
    linebreak1;
    trav(ans) print(x);
    linebreak1;
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