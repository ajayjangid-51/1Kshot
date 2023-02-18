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

void solve()
{
    // vi v = {1, 3, 4, 2, 5, 3, 4, 2};
    // vi v = {1, 2, 3, 4};
    vi v = {3, 3, 4, 2, 4};
    stack<int> s;
    int n = size(v);
    vi left(n);
    left[0] = -1;
    vi right(n);
    right[n - 1] = n;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() and v[s.top()] >= v[i])
        {
            s.pop();
        }
        if (s.empty())
            left[i] = -1;
        else
            left[i] = s.top();
        s.push(i);
    }
    linebreak1;
    trav(left) print(x);
    linebreak1;
    while (!s.empty())
        s.pop();
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() and v[s.top()] >= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            right[i] = n;
        }
        else
            right[i] = s.top();
        s.push(i);
    }
    trav(right) print(x);
    linebreak1;
    vi ans(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len - 1] = max(ans[len - 1], v[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
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