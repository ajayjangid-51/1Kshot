#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
void solve()
{
    // int n = 1, d = 2;
    // int n = 1, d = 6;
    // int n = 7, d = -12;
    // int n = -1, d = -2147483648;
    // int n = 2147483647, d = 37;
    int nn = -2147483648, dd = 1;
    long long n = nn;
    long long d = dd;
    // int n = 4, d = 333;
    string ans;
    if (n < 0 ^ d < 0)
    {
        ans.push_back('-');
    }
    n = abs(n);
    d = abs(d);
    deb(n);
    deb(d);
    ans += to_string(n / d);
    debline(ans);
    if (n % d == 0)
    {
        debline(ans);
        return;
    }
    else
        ans += ".";

    int inx = ans.size();
    map<int, int> m;
    long long r = (long long)n % d;
    deb(r);
    while (!m.count(r))
    {
        m[r] = inx;
        inx++;
        r *= 10;
        ans += to_string(r / d);
        r = r % d;
        if (r == 0)
        {
            debline(ans);
            return;
        }
    }
    ans.insert(m[r], "(");
    ans += ")";
    debline(ans);
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