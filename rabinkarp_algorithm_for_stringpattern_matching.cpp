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
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    int a = 28;
    // int mod = 5961;
    int mod = 1e7 + 5;

    vector<int> power28((1e5 + 1));
    debline(power28.size()); // power28[i] = value of 28^i.
    power28[0] = 1;

    for (int i = 1; i < power28.size(); i++)
    {
        power28[i] = ((long long)power28[i - 1] * 28) % mod;
    }

    debline(power28[1]);
    debline(power28[2]);
    debline(power28[10]);

    int hash_p = 0;
    int hash_s = 0;
    for (int i = 0; i < m; i++)
    {
        hash_p = (hash_p + (long long)((p[i] - 'a') + 1) * power28[m - (i + 1)]) % mod;
        // deb(hash_p);
        hash_s = (hash_s + (long long)((s[i] - 'a') + 1) * power28[m - (i + 1)]) % mod;
        deb(hash_s);
    }

    debline(hash_p);
    debline(hash_s);
    linebreak1;
    vector<int> ans;

    for (int i = m; i < n + 1; i++)
    {
        // now first roll the hash_s.
        // print(s[i - m]);
        // nline;
        if (hash_s == hash_p)
        {
            print('1');
            bool b = 1;
            for (int j = 0; j < m; j++)
            {
                deb2(p[j], s[i - (m - j)]);
                if (p[j] != s[i - (m - j)])
                {
                    b = 0;
                }
            }
            if (b)
            {
                ans.push_back((i - m) + 1);
            }

            if (i == n)
                break;
        }
        int l = (s[i - m] - 'a') + 1;
        l = ((long long)l * power28[m - 1]) % mod;
        // deb(l);
        // deb(hash_s);
        hash_s = (((hash_s + mod - (l)) % mod * (long long)28) % mod + ((s[i] - 'a') + 1)) % mod;
        // hash_s = (((long long)(hash_s - ((long long)((s[i - m] - 'a') + 1) * power28[m - 1]) % mod) * 28) % mod + (long long)s[(i - 'a') + 1]) % mod;
        deb(hash_s);
        // linebreak1;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}