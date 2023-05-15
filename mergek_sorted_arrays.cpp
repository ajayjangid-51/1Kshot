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

vi merge(vi &v1, vi &v2)
{
    int i = 0;
    vi v(v1.size() + v2.size());
    int j = 0, k = 0;
    while (j < v1.size() and k < v2.size())
    {
        if (v1[j] <= v2[k])
        {
            v[i++] = v1[j++];
        }
        else
        {
            v[i++] = v2[k++];
        }
    }
    while (j < v1.size())
    {
        v[i++] = v1[j++];
    }
    while (k < v2.size())
    {
        v[i++] = v2[k++];
    }
    linebreak1;
    trav(v) print(x);
    return v;
}
vi fn(int s, int e, vvi &v)
{
    if (s == e)
        return v[s];
    int mid = (s + e) / 2;

    vi v1 = fn(s, mid, v);
    vi v2 = fn(mid + 1, e, v);
    return merge(v1, v2);
}
void solve()
{
    int k;
    cin >> k;
    vvi v(k, vi(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> v[i][j];
        }
    }
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }

    vi ans = fn(0, k - 1, v);
    print("hi");

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