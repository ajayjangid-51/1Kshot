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
    // vi v = {1, 2, 3, 4};
    vi v = {3, 3, 4, 2, 4};
    int n = size(v);
    vi ans;
    for (int k = 1; k <= n; k++)
    {
        int ws = k;
        deque<int> dq;
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        for (; j < k; j++)
        {
            while (!dq.empty() and dq.back() > v[j])
            {
                dq.pop_back();
            }
            dq.push_back(v[j]);
        }
        maxi = max(maxi, dq.front());
        i++;
        for (; j < n; j++)
        {
            // deb2(i, j);
            if (dq.front() == v[i - 1])
            {
                dq.pop_front();
            }
            while (!dq.empty() and dq.back() > v[j])
            {
                dq.pop_back();
            }
            dq.push_back(v[j]);
            i++;
            maxi = max(maxi, dq.front());
            linebreak1;
        }
        // debline(maxi);
        // ans.push_bac
        ans.push_back(maxi);
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