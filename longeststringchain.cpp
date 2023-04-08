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
    int n;
    cin >> n;
    int k = 0;
    vs v(n);
    while (cin >> v[k])
        k++;
    sort(range(v), [](string a, string b)
         { return a.size() < b.size(); });
    linebreak1;
    trav(v) print(x);

    // trav(v)

    vi lis(n, 1);
    int maxi = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            // int s = abs((int)v[i].size() - (int)v[j].size());
            // int s = 0;
            // deb(s);

            // if ((int)(abs((v[i].size()) - v[j].size())) > 1)
            // if (s > 1)
            //     continue;
            if (v[j].size() - v[i].size() > 1)
                continue;

            if (v[j].size() == v[i].size() and v[j] != v[i])
                continue;
            int k = min(v[i].size(), v[j].size());
            int cnt = k;
            for (int l = 0; l < k; l++)
            {
                if (v[i][l] != v[j][l])
                {
                    cnt = l;
                    break;
                }
            }
            int cnt2 = k;
            int l1 = v[i].size() - 1, l2 = v[j].size() - 1;
            for (int l = 0; l < k; l++)
            {
                if (v[i][l1] != v[j][l2])
                {
                    cnt2 = l;
                    break;
                }
                l1--;
                l2--;
            }
            // cnt++;
            // deb2(cnt, cnt2);
            if ((v[j].size() - (cnt2 + cnt)) == 1 or v[i] == v[j])
            {
                print(v[j]);
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        // nline;
        maxi = max(maxi, lis[i]);
    }
    debline(maxi);
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