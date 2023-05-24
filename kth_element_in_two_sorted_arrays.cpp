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
int findFloor(vector<int> v, int n, int x)
{

    // Your code here
    int ans = -1;
    int s = 0, e = n - 1;
    while (s >= 0 and e <= n - 1 and s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}
// this solution will not work in duplicates elements in array.
// like:-
/* 4 5 3
1 1 1 1 1 1 1 1 1
 */
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi v1(n), v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int j = 0; j < m; j++)
        cin >> v2[j];
    linebreak1;
    trav(v1) print(x);
    nline;
    trav(v2) print(x);
    linebreak1;

    int s = min(v1[0], v2[0]), e = max(v1.back(), v2.back());
    // auto i1 = lower_bound(v2.begin(), v2.end(), 5) - v2.begin();
    // debline(i1);

    while (s <= e)
    {
        // break;
        int mid = (s + e) / 2;
        // deb(mid);
        auto i1 = findFloor(v1, n, mid);
        // auto i2 = findFloor(range(v2), mid) - v2.begin();/
        auto i2 = findFloor(v2, m, mid);
        int t = i1 + i2 + 2;
        // deb2(i1, i2);
        // deb(t);
        // nline;
        if (t == k)
        {
            debline(max(v1[i1], v2[i2]));
            return;
        }
        if (t < k)
        {
            // see in right side
            s = min(v1[i1 + 1], v2[i2 + 1]);
        }
        else
        {
            e = max(v1[i1 - 1], v2[i2 - 1]);
        }
    }
    debline("-1");
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