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

void prime(vi &p)
{

    int low = 1, high = 1000, i;
    bool is_prime = true;

    while (low < high)
    {
        is_prime = true;

        // 0 and 1 are not prime numbers
        if (low == 0 || low == 1)
        {
            is_prime = false;
        }

        for (i = 2; i <= low / 2; ++i)
        {
            if (low % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            p.push_back(low);

        ++low;
    }
    linebreak1;
    trav(p) print(x);
    linebreak1;
}

void solve()
{
    // vi v = {4, 9, 6, 10};
    vi v = {5, 8, 3};
    int n = v.size();
    vi p;
    prime(p);
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
            continue;

        int x = v[i] - v[i + 1];
        deb(x);
        int b = 0;

        for (auto y : p)
        {
            if (y > x and y != v[i])
            {
                deb(y);
                b = 1;
                v[i] -= y;
                break;
            }
        }
        if (!b)
        {
            debline("false");
            return;
        }
    }

    debline("true");
    linebreak1;
    trav(v) print(x);
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