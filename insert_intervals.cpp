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
    int n;
    cin >> n;
    vvi v(n, vi(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    vi nv(2);
    cin >> nv[0] >> nv[1];
    trav(v)
    {
        print(x[0]), print(x[1]), nline;
    }
    // print(nv[0]), print(nv[1]), nline;

    vvi ans;
    int i = 0;
    bool b = 0;
    for (; i < n; i++)
    {
        if (nv[1] < v[i][0])
        { // before
            ans.push_back({nv});
            b = 1;
            break;
        }
        else if (nv[0] > v[i][1])
        { // after
            ans.push_back(v[i]);
            // ans.push_back({nv});
            // i++;
            // break;
        }
        else
        { // overlap
            nv[0] = min(nv[0], v[i][0]);
            nv[1] = max(nv[1], v[i][1]);
        }
    }
    while (i < n)
    {
        ans.push_back(v[i]);
        i++;
    }
    if (!b)
        ans.push_back(nv);
    linebreak1;
    trav(ans)
    {
        print(x[0]), print(x[1]), nline;
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