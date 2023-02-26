// notepoint:- toposort not possible via pure bfs , we have a "kahn's algorithms" which not actually bfs, if we see it from higher height, then we somewhat feels that it is like bfs means it like trav q while it is not empty and push and pop from queue.. somewhat similar....

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
    // vi adj[] = {
    //     {},
    //     {3},
    //     {3},
    //     {},
    //     {0, 1},
    //     {0, 2}};
    // vi adj[] = {
    //     {},
    //     {0},
    //     {0},
    //     {0},
    // };
    vi adj[] = {
        {2}, {}, {}, {0, 2}};
    int n = 4;
    vb visited(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     if (siz(adj[i]))
    //     {
    //         visited[i] = 0;
    //         trav2(adj[i]) visited[y] = 0;
    //     }
    // }
    stack<int> s;
    queue<int> q;
    vvi ans2;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            s.push(i);
            vi ans;
            while (!q.empty())
            {
                int f = q.front();
                q.pop();
                // if (visited[f])
                //     continue;
                visited[f] = 1;
                // s.push(f);
                for (auto x : adj[f])
                {
                    if (!visited[x])
                    {

                        s.push(x);
                        q.push(x);
                    }
                }
            }
            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            reverse(range(ans));
            ans2.push_back(ans);
        }
    }
    trav(ans2)
    {
        trav2(x) print(y);
        nline;
    }
    vi ans;
    for (int i = siz(ans2) - 1; i >= 0; i--)
    {
        for (auto x : ans2[i])
            ans.push_back(x);
    }
    linebreak1;
    trav(ans) print(x);
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