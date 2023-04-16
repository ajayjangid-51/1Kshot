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
    int b = 1e7, c = 1e3;
    int bc = b * c;
    deb(bc);
    int d = (b * c) % MOD;
    deb(d);
    long long e = (long long)b * c;
    deb(e);
    long long f = e % MOD;
    deb(f);
    int g = ((long long)(b % MOD) * (c % MOD)) % MOD; // so first always typecast it into long long and do multiply and mode.
    deb(g);
    int h = b % MOD;
    deb(h);
    int l = c % MOD;
    deb(l);

    //

    int a = 1e7, b = 1e3;
    int ab = a * b;
    deb(ab);
    long long c = a * b;
    deb(c);
    long long e = (long long)a * b;
    deb(e);

    long long d = 1e14 - INT_MAX;
    int max1 = INT_MAX + 1;
    deb(max1);
    max1--;
    deb(max1);
    deb((int)1e9);
    deb(d);
    // int t =

    long long f = pow(2, 31);
    long long g = pow(2, 32);
    deb(f);
    deb(g);
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