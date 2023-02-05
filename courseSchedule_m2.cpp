#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define size(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "_______________________________" \
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
bool fn(int i, stack<int> &s, vb &rec, vb &visited, vvi &adj)
{
    if (rec[i])
        return 1;
    rec[i] = 1;
    visited[i] = 1;
    for (auto x : adj[i])
    {
        // if (rec[x])
        //     return 1;
        // else if (!visited[x])
        // {
        if (fn(x, s, rec, visited, adj))
            return 1;
        // }
    }
    rec[i] = 0;
    s.push(i);
    return 0;
}
void solve()
{
    int n = 2;
    vvi adj = {{1}, {0}};
    trav(adj)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
    linebreak1;
    vb rec(n, 0);
    vb visited(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (fn(i, s, rec, visited, adj))
            {
                debline("empty");
                return;
            }
        }
    }
    debline("hello");
    vi ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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

/* #define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define size(a) a.size();
class Solution {
public:
bool fn(int i, stack<int> &s, vb &rec, vb &visited, vvi &adj)
{
    if (rec[i])
        return 1;
    if(visited[i]) return 1;
    rec[i] = 1;
    visited[i] = 1;
    for (auto x : adj[i])
    {
        // if (rec[x])
        //     return 1;
        // else if (!visited[x])
        // {
        if (fn(x, s, rec, visited, adj))
            return 1;
        // }
    }
    rec[i] = 0;
    // s.push(i);
    return 0;
}
    bool canFinish(int n, vector<vector<int>>& p) {
        vvi adj(n);
        for(auto x:p){
            adj[x[1]].push_back(x[0]);
        }
          vb rec(n, 0);
    vb visited(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (fn(i, s, rec, visited, adj))
            {
                // debline("empty");
                return 0;
                // return {};
            }
        }
    }
    // debline("hello");
    // vi ans;
    // while (!s.empty())
    // {
    //     ans.push_back(s.top());
    //     s.pop();
    // }
    // return ans;
    return 1;
    }
}; */