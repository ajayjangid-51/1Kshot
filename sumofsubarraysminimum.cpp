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
    // vi v = {3, 1, 2, 4};
    // vi v = {11, 81, 94, 43, 3};
    vi v = {117, 1315, 1336, 4213, 5634, 6288, 7640, 8533, 9688, 10186, 10593, 11896, 13673, 14707, 15484, 17429, 19639, 20416, 21375, 23601, 25800, 26485, 27893, 28026, 28695, 29121, 28642, 28023, 27642, 26324, 23844, 22069, 21124, 20181, 18957, 15736, 15364, 13749, 13612, 11062, 10319, 9755, 9367, 7977, 6463, 6049, 4886, 3071, 1331, 865};
    int n = size(v);
    vi ple(n); // ple (previous lesser element)
    vi nle(n); // nle (next lesser element)
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and v[s.top()] >= v[i])
        {
            s.pop();
        }
        if (s.empty())
            ple[i] = -1;
        else
            ple[i] = s.top();
        s.push(i);
    }
    trav(ple) print(x);
    linebreak1;
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and v[s.top()] > v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            nle[i] = n;
        }
        else
        {
            nle[i] = s.top();
        }
        s.push(i);
    }
    trav(nle) print(x);
    linebreak1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // deb3((i - ple[i]), (nle[i] - i), v[i]);
        int p = (i - (ple[i])) * (nle[i] - i) * (v[i]);
        // deb(p);
        sum = (sum + p) % MOD;
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