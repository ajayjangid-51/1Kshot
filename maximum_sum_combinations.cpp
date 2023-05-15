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

void solve()
{
    int n, c;
    cin >> n >> c;
    vi A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    linebreak1;
    trav(A) print(x);
    nline;
    trav(B) print(x);
    linebreak1;
    sort(range(A), greater<int>());
    sort(range(B), greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;
    //                 <sum , <Aindex , Bindex>>
    pq.push({A[0] + B[0], {0, 0}});
    debline(pq.top().first);
    vector<vector<bool>> vis(n, vb(n, 0));
    vi ans;

    while (!pq.empty() and ans.size() < c)
    {
        pair<int, pii> p = pq.top();
        int i = p.second.first;
        int j = p.second.second;
        deb(p.first);
        pq.pop();
        if (vis[i][j])
            continue;
        ans.push_back(p.first);
        if (j + 1 < n)
            pq.push({(A[i] + B[j + 1]), {i, j + 1}});
        if (i + 1 < n)
            pq.push({(B[j] + A[i + 1]), {i + 1, j}});
    }

    linebreak1;
    for (int i = 0; i < c; i++)
    {
        print(ans[i]);
    }
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