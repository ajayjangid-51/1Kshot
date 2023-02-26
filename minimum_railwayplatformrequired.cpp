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
    vi a = {900, 940, 950, 1100, 1500, 1800};
    vi d = {910, 1200, 1120, 1130, 1900, 2000};
    // can use priority queue:- to get the soonest departing train station:-
    vector<pair<int, int>> p;
    int n = siz(a);
    for (int i = 0; i < n; i++)
    {
        p.push_back({a[i], d[i]});
    }
    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b)
         {
        if(a.first<b.first) return 1;
        return 0; });

    linebreak1;
    trav(p)
    {
        deb2(x.first, x.second);
    }
    linebreak1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(p[0].second);
    for (int i = 1; i < n; i++)
    {
        if (pq.top() < p[i].first)
        {
            debline(pq.top());
            pq.pop();
            pq.push(p[i].second);
        }
        else
        {
            pq.push(p[i].second);
        }
    }
    debline(size(pq));
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