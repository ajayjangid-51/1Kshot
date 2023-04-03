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
    vs v = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5, k = 4;
    vvi adj(k);
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = v[i], s2 = v[i + 1];
        int j = 0;
        while (j < s1.size() and j < s2.size() and (s1[j] == s2[j]))
            j++;
        if (j < s1.size() and j < s2.size())
        {
            deb2(s1[j], s2[j]);
            int a = s1[j] - 'a', b = s2[j] - 'a';
            deb2(a, b);
            adj[a].push_back(b);
        }
    }
    linebreak1;
    for (int i = 0; i < k; i++)
    {
        print(char(i + 'a')), print(":-");
        for (auto x : adj[i])
        {
            print(char(x + 'a'));
        }
        nline;
    }

    // get toposort of adj:
    n = k;
    vi indegree(n, 0);
    trav(adj)
    {
        trav2(x)
        {
            indegree[y]++;
        }
    }
    linebreak1;
    string ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    linebreak1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        ans.push_back(char(f + 'a'));
        for (auto x : adj[f])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}