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
const int mod = 1e9 + 7;
void solve()
{
    int n, d;
    cin >> n >> d;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int summ = 0;
    for (int i = 0; i < n; i++)
    {
        // cin >> v[i];
        summ += v[i];
    }
    deb(summ);
    int sum = (summ + d) / 2;
    // sum--;
    // sum/=2;
    // trav(v) print(x);

    vb s(sum + 1, 0);
    s[0] = 1;
    vector<long long> cnt(sum + 1, 0);
    cnt[0] = 1;
    deb(sum);

    for (int i = n - 1; i >= 0; i--)
    {
        vi tmp;
        // vector<long long> cnt2 = cnt;
        vector<long long> cnt2(sum + 1, 0);
        for (int j = 0; j <= sum; j++)
        {
            if (s[j])
                tmp.push_back(j);
        }
        trav(tmp)
        {
            if (x + v[i] <= sum)
            {
                s[x + v[i]] = 1;
                cnt2[x + v[i]] = cnt[x];
            }
        }
        // cnt = cnt2;
        for (int i = 0; i <= sum; i++)
        {
            cnt[i] = (cnt[i] + cnt2[i]) % mod;
            // cnt[i] = cnt2[i] + 1;
        }
        // cnt[0] = 1;
    }
    int c = 0;
    linebreak1;
    trav(s) print(x);
    linebreak1;
    // trav(cnt) print(x);
    linebreak1;

    // for (int i = 0; i <= sum; i++)
    // {
    //     int s2 = summ - i;
    //     if (abs(s2 - i) == d)
    //     {
    //         c += cnt[i];
    //     }
    // }
    // deb(c);
    debline(cnt[sum]);
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